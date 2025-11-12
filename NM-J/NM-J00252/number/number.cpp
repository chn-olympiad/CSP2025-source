#include <bits/stdc++.h>
using namespace std;
int c[20], l;
char s[1000100];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    l = strlen(s + 1);
    for ( int i = 1; i <= l; i++ )
        if ( '0' <= s[i] && s[i] <= '9' )
            c[s[i] - '0']++;
    for ( int i = 9; i >= 0; i-- )
        if ( c[i] )
            for ( int j = 1; j <= c[i]; j++ )
                printf("%d", i);
    return 0;
}
