#include <bits/stdc++.h>
using namespace std;
int n,a[100005][3],ans=-1;
void dfs(int i,int s,int c1,int c2,int c3)
{
    if(c1>n/2||c2>n/2||c3>n/2) return;
    if(i>n)
    {
        ans=max(ans,s);
        return;
    }
    dfs(i+1,s+a[i][0],c1+1,c2,c3);
    dfs(i+1,s+a[i][1],c1,c2+1,c3);
    dfs(i+1,s+a[i][2],c1,c2,c3+1);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        ans=-1;
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
}
