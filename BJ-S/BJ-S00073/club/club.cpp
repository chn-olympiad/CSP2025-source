#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],c[N];
int ans,n,lim;
void dfs(int x,int cnta,int cntb,int cntc,int sum)
{
    if(x>n)
    {
        ans=max(ans,sum);
        return ;
    }
    if(cnta<lim)
    {
        dfs(x+1,cnta+1,cntb,cntc,sum+a[x]);
    }
    if(cntb<lim)
    {
        dfs(x+1,cnta,cntb+1,cntc,sum+b[x]);
    }
    if(cntc<lim)
    {
        dfs(x+1,cnta,cntb,cntc+1,sum+c[x]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        lim=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
