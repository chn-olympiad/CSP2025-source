#include<bits/stdc++.h>

using namespace std;

const int maxn = 550;
long long int ans , a[maxn] , b[maxn] , n , m;
bool flag[maxn];
string s;

void dfs( int now , int num )
{
    if( now == n + 1 )
    {
        if( num >= m )
            ans = ( ans + 1 ) % 998244353;
        return;
    }
    for( int i = 1 ; i <= n ; ++i )
    {
        if( flag[i] == 0 && a[i] < n - num )
        {
            flag[i] = 1;
            if( b[now] == 1 )
                dfs( now + 1 , num + 1 );
            if( b[now] == 0 )
                dfs( now + 1 , num );
            flag[i] = 0;
        }
    }
}

int main()
{
    freopen( "employ.in" , "r" , stdin );
    freopen( "employ.out" , "w" , stdout );
    cin >> n >> m;
    cin >> s;
    for( int i = 1 ; i <= n ; ++i )
        cin >> a[i];
    for( int i = 1 ; i <= n ; ++i )
        b[i] = s[i - 1] - '0';
    dfs( 1 , 0 );
    cout << ans << endl;
    return 0;
}
