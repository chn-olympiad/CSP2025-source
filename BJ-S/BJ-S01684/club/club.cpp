#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+8;
int t,n,ans,vis[N];
int a[N],b[N],c[N];
void dfs(int num,int sum)
{
    if(num==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(vis[i]>=(n/2))
        {
            continue;
        }
        vis[i]++;
        if(i==1)
        {
            dfs(num+1,sum+a[num]);
        }
        else if(i==2)
        {
            dfs(num+1,sum+b[num]);
        }
        else
        {
            dfs(num+1,sum+c[num]);
        }
        vis[i]--;
    }
}
void dfsb(int num,int sum)
{
    if(num==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=2;i++)
    {
        if(vis[i]>=(n/2))
        {
            continue;
        }
        vis[i]++;
        if(i==1)
        {
            dfs(num+1,sum+a[num]);
        }
        else if(i==2)
        {
            dfs(num+1,sum+b[num]);
        }
        vis[i]--;
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        ans=-1;
        cin>>n;
        bool f=1,fb=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(c[i]>0) f=0;
            if(b[i]>0) fb=0;
        }
        if(f && !fb)
        {
            dfsb(1,0);
            cout<<ans<<endl;
            continue;
        }
        if(f&&fb)
        {
            sort(a+1,a+n+1,cmp);
            int cnt=0;
            for(int i=1;i<=n/2;i++)
            {
                cnt+=a[i];
            }
            cout<<cnt<<endl;
            continue;
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
