#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;
string s;
int num[MAXN], len = 0, maxnum = 0;
bool cmp(int x, int y){
    return x > y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0;i < s.length();i++){
        if(isdigit(s[i])){
            int gnum = s[i] - '0';
            maxnum = max(maxnum, gnum);
            num[++len] = s[i] - '0';
        }
    }
    if(maxnum == 0){
        puts("0");
        return 0;
    }
    sort(num + 1, num + 1 + len, cmp);
    for(int i = 1;i <= len;i++) printf("%d", num[i]);
    printf("\n");
    return 0;
}
