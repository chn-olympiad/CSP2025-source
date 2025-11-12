#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
const int N=200+10;
int a[N][3];
int n;
void dfs(int p,int c0,int c1,int c2,int val)
{
    if(c0>n/2||c1>n/2||c2>n/2) return;
    if(p>n)
    {
        ans=max(ans,val);
        return;
    }
    dfs(p+1,c0+1,c1,c2,val+a[p][0]);
    dfs(p+1,c0,c1+1,c2,val+a[p][1]);
    dfs(p+1,c0,c1,c2+1,val+a[p][2]);

}
void solve()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
    }
    ans=0;
    dfs(1,0,0,0,0);
    cout<<ans<<endl;
}


signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }





    return 0;
}
