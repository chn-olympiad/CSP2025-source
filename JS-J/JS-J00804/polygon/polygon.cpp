#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,a[5007],ans=0;
void dfs(int mx,int sum,int now)
{
    if(now>n)
    {
        if(sum>2*mx)
        {
            ans++;
        }
        return ;
    }
    //choose
    dfs(max(mx,a[now]),sum+a[now],now+1);
    dfs(mx,sum,now+1);
    return ;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
