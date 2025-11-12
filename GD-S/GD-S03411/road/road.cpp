#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	
	return 0;
}
/*
{
    "md5_check": [
        {
            "name": "csps.zip",
            "md5": "fed5a2e2b397fc303476cd0185c11d65"
        }
    ],
    "root_path": "D:\\",
    "regex": "^GD-S\\d{5}$",
    "problems": [
        {
            "name": "club",
            "regex": "^club\\\\club\\.(cpp|c|pas)$"
        },
        {
            "name": "road",
            "regex": "^road\\\\road\\.(cpp|c|pas)$"
        },
        {
            "name": "replace",
            "regex": "^replace\\\\replace\\.(cpp|c|pas)$"
        },
        {
            "name": "employ",
            "regex": "^employ\\\\employ\\.(cpp|c|pas)$"
        }
    ],
    "start_time": "2025-11-01T14:30:00+08:00",
    "end_time": "2025-11-01T18:30:00+08:00",
    "size_limit_kb": 100
}

@echo off
setlocal enabledelayedexpansion

set "problems="

for %%a in (1 2 3 4) do (
    set /p "p%%a=Enter problem name %%a: "
    set "problems=!problems! !p%%a!"
)

(
echo {
echo     "md5_check": [
echo         {
echo             "name": "csps.zip",
echo             "md5": "fed5a2e2b397fc303476cd0185c11d65"
echo         }
echo     ],
echo     "root_path": "D:\\",
echo     "regex": "^GD-S\\d{5}$",
echo     "problems": [
) > "D:\checker.cfg.json"

set /a count=0
for %%a in (%problems%) do (
    set /a count+=1
    if !count! lss 4 (
        set "comma=,"
    ) else (
        set "comma="
    )
    (
    echo         {
    echo             "name": "%%a",
    echo             "regex": "^%%a\\\\%%a\\.(cpp|c|pas)$"
    echo         }!comma!
    ) >> "D:\checker.cfg.json"
)

(
echo     ],
echo     "start_time": "2025-11-01T14:30:00+08:00",
echo     "end_time": "2025-11-01T18:30:00+08:00",
echo     "size_limit_kb": 100
echo }
) >> "D:\checker.cfg.json"

echo Created D:\checker.cfg.json
pause
*/
 
