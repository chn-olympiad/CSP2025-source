#include<bits/stdc++.h>
using namespace std;
int n, m, c[505], cnt = 0, vis[505], c2[505], a[505];
long long ans = 0, mod = 998244353;
    string s;
void dfs( int state )
{
    if( cnt == m )
    {
/*        cout << state << endl;
        for( int i = 1; i <= n; i++ )
            cout << a[i] << " ";
        cout << endl;
 */       ans++;
        return;
    }
    if( state == n+1 )
    {
        return;
    }
    for( int i = 1; i <= n; i++ )
    {
        if( vis[i] == 0 )
        {
            vis[i] = 1;
            if( c[i] > c2[state] && s[state] == '0' )
                cnt++;
 //           a[state] = i;
            dfs(state+1);
            vis[i] = 0;
            if( c[i] > c2[state] && s[state] == '0' )
                cnt--;
        }
    }
}
int main()
{
    freopen( "employ.in", "r", stdin );
    freopen( "employ.out", "w", stdout );
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for( int i = 1; i <= n; i++ )
    {
        c2[i] = cnt;
        if( s[i] == '1' )
            cnt++;
    }
    for( int i = 1; i <= n; i++ )
        cin >> c[i];
    cnt = 0;
    dfs(1);
    cout << ans % mod << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
