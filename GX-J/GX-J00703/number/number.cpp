#include<bits/stdc++.h>
using namespace std;
int a[10] ;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s ;
    cin >> s ;
    int n = s.size() ;
    memset(a,0,sizeof(a));
    for ( int i = 0 ; i < n ; i++)
    {
        if ( s[i] >= '0' && s[i] <= '9' )
        {
            int d = s[i]-'0' ;
            a[d]++;
        }
    }
    for ( int i = 9 ; i >= 0 ; i -- )
    {
        while(a[i]>0)
        {
            cout << i ;
            a[i]--;
        }
    }
    return 0;
}
