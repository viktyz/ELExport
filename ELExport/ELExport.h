//
//  ELExport.h
//  ELog
//
//  Created by viktyz on 16/9/21.
//  Copyright © 2016年 AlfredJiang. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ELog(s, ...) [[ELExport sharedExport] file:__FILE__ function: (char *)__FUNCTION__ lineNumber:__LINE__ formatString:(s),##__VA_ARGS__]

#define ESLog(__status__,s, ...) [[ELExport sharedExport] file:__FILE__ status:__status__ function: (char *)__FUNCTION__ lineNumber:__LINE__ formatString:(s),##__VA_ARGS__]

#define EILog(__instance__,s, ...) [__instance__ file:__FILE__ function: (char *)__FUNCTION__ lineNumber:__LINE__ formatString:(s),##__VA_ARGS__]

#define EISLog(__instance__,__status__,s, ...) [__instance__ file:__FILE__ status:__status__ function: (char *)__FUNCTION__ lineNumber:__LINE__ formatString:(s),##__VA_ARGS__]

@interface ELELog : NSObject

@property (nonatomic, strong) NSString *path;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) NSString *file;
@property (nonatomic, strong) NSString *function;
@property (nonatomic, assign) NSInteger lineNumber;
@property (nonatomic, strong) NSString *print;

- (instancetype)initWithInfo:(NSString *)info;

@end

@interface ELEFile : NSObject

@property (nonatomic, strong) NSString *path;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray<ELELog *> *allLogs;

- (instancetype)initWithPath:(NSString *)path;

@end

@interface ELExport : NSObject

@property (nonatomic, assign, readonly) BOOL enbaleElog;            //Default is 'YES'
@property (nonatomic, assign) NSInteger maxTempLineCount;           //Default is '25'
@property (nonatomic, assign) NSStringEncoding stringEncoding;      //Default is 'NSUTF8StringEncoding'
@property (nonatomic, strong) NSString *exportDirectoryName;        //Default is 'ELog'
@property (nonatomic, strong) NSString *easyExportDirectoryName;    //Default is 'Easy_Export'
@property (nonatomic, strong) NSString *exportFileName;             //Default is string type of date
@property (nonatomic, strong) NSString *exportFileType;             //Default is 'csv'

+ (instancetype)sharedExport;

- (instancetype)initWithLogDirectoryName:(NSString *)directoryName
                    easyLogDirectoryName:(NSString *)easyDirectoryName;

- (void)enableELog:(BOOL)enable;

#pragma mark - String Tools

- (NSString*)stringFromObject:(id)object
                     encoding:(NSStringEncoding)encoding;

- (NSString *)easyWriteString:(NSString *)string
                       toFile:(NSString *)fileName;

#pragma mark - Write file

- (void)file:(char*)source
    function:(char*)functionName
  lineNumber:(NSInteger)lineNumber
formatString:(NSString*)formatString, ...;

- (void)file:(char*)source
      status:(NSString *)status
    function:(char*)functionName
  lineNumber:(NSInteger)lineNumber
formatString:(NSString*)formatString, ...;

#pragma mark - Log

- (NSString *)logFilePath;

- (NSArray<ELEFile *> *)allLogFiles;

- (void)clearAllLogFiles;

#pragma mark - Easy Log

- (NSString *)easyLogDirectoryPath;

- (NSDictionary *)allEasyLogFiles;

- (void)clearAllEasyLogFiles;

#pragma mark - Synchronize

- (void)synchronize;

@end
