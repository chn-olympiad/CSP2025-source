#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll inf=1000000000000LL;
ll n,mp[100001][4],dp[31][31][31][31];
ll dfs(ll i,ll x,ll y,ll z)
{
    if(dp[i][x][y][z]!=0) return dp[i][x][y][z];
    if(x>n/2 || y>n/2 || z>n/2) return -inf;
    if(i==n+1) return 0;
    return dp[i][x][y][z]=max({dfs(i+1,x+1,y,z)+mp[i][1],dfs(i+1,x,y+1,z)+mp[i][2],dfs(i+1,x,y,z+1)+mp[i][3]});
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin>>T;
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=3;j++)
            {
                cin>>mp[i][j];
            }
        }
        cout<<dfs(1,0,0,0)<<endl;
    }
    cout<<flush;
    return 0;
}
