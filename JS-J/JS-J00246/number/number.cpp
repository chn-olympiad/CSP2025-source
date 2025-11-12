#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e6+5 ;
int a[N] ;
int main()
{
    freopen("number.in", "r", stdin) ;
    freopen("number.out", "w", stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    string s ;
    cin >> s ;
    ll n = s.size() ;
    int k = 1 ;
    for(ll i = 0 ; i < n ; i ++)
    {
        if(s[i]>= '0' && s[i] <= '9')
        {
            a[k]= s[i] - '0' ;
            k ++ ;
        }
    }
    sort(a+1, a+k) ;
    for(int i = k-1 ; i >= 1 ; i --)
        cout << a[i] ;
    cout << '\n' ;
    return 0 ;
}

