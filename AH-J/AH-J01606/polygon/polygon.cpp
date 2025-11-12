#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,ans=0,m=998244353;
vector<int> adj(5005);

void bfs(int x,int cnt,int sum,int i)
{
    if(i>=n) return;
    //不选
    bfs(x,cnt,sum,i+1);
    //选
    cnt=max(cnt,adj[i]);
    sum=(sum+adj[i])%m;
    if(x==1)
    {
        if(sum>cnt*2) ans=(ans+1)%998244353;
    }
    else{
        bfs(x-1,cnt,sum,i+1);
    }

}

int cp(int x,int y)
{
    int fz=1,fm=1,n=y;
    for(int i=1;i<=n;i++)
    {
        fz*=x,fm*=y;
        x--,y--;
    }
    return fz/fm;
}

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>adj[i];
    }

    for(int i=0;i<n;i++)
    {
        if(adj[i]!=1)
        {
            for(int i=3;i<=n;i++)
            {
                bfs(i,0,0,0);
            }
            cout<<ans%m<<endl;
            return 0;
        }
    }
    for(int i=4;i<=n;i++)
    {
        ans=(ans+cp(n,i))%m;
    }
    cout<<ans<<endl;
    return 0;
}

