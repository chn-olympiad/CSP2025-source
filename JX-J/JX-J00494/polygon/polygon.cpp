#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998224353;
int a[5005];
int ans=0;
int n;
bool vis[5005];
void dfs(int i,int maxn,int sum,int c)
{
    if(i>n)
    {
        if(c>=3&&sum>2*maxn)
        {
            ans++;
            ans%=MOD;
        }
    }
    else
    {
        dfs(i+1,max(maxn,a[i]),sum+a[i],c+1);
        dfs(i+1,maxn,sum,c);
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dfs(1,0,0,0);
    cout << ans;
    return 0;
}
