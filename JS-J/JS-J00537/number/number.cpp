#include <bits/stdc++.h>

using namespace std;

const int N = 15;

string s;
int a[N];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i ++) {
        if ('0' <= s[i] && s[i] <= '9') {
            a[s[i] - '0'] ++ ;
        }
    }
    int flag = 0;
    for (int i = 9; i >= 0; i -- ) {
        if(!flag && i == 0) {
            puts("0");
            continue;
        }
        while(a[i])
        {
            a[i] -- ;
            putchar(i + '0');
            flag = 1;
        }
    }
    printf("\n");
    return 0;
}