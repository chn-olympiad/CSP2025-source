#include<bits/stdc++.h>
using namespace std ;

char a[1000010] ;

bool cmp(char p, char q)
{
    return p > q ;
}

int main()
{
    freopen("number.in", "r", stdin) ;
    freopen("number.out", "w", stdout) ;

    string s ;
    getline(cin, s) ;
    long long len = s.size() ;
    if(len == 1)
    {
        cout << s ;
        return 0 ;
    }
    for(long long i=0; i<len; i++)
    {
        a[i] = 'o' ;
        if(char(s[i]) >= 48 && char(s[i]) <= 57)
        {
            a[i] = s[i] ;
        }
    }
    sort(a, a+len, cmp) ;
    for(long long i=0; i<len; i++)
    {
        if(a[i] == 'o') continue ;
        else cout << a[i] ;
    }
    return 0 ;
}
