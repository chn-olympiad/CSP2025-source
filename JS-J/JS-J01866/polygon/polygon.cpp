#include <bits/stdc++.h>

using namespace std;
const int x = 998244353;
int n ,ans;
vector<int> v;
void dfs( int r ,int t,int last , int maxn , int sum)
{
    if (t == r)
    {
        if (sum > maxn * 2)
        {
            ans++;
            ans %= x;
            return;
        }
    }
    for (int i = last+1 ; i <= n ; i++ )
    {
        dfs(r ,t+1,i,max(maxn,v[i]), sum+v[i]);
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin );
    freopen("polygon.out" , "w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    v.resize(n+5);
    for ( int i = 1 ; i <= n ; i++ )
    {
        int a;
        cin >> a;
        v[i] = a;
    }
    for (int i = 3 ; i <= n ; i++ )
    {
        dfs(i , 0 , 0,0,0);

    }
    cout << ans << endl;
    return 0;
}
