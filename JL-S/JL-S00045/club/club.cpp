#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id,u,v,dis;
    bool operator < (const node&x)const
    {
        return dis<x.dis;
    }
};
struct edge
{
    int u,dis;
};
edge a[100005][5];
priority_queue<node>q;
priority_queue<node>q2;
int vis[100005],num[5];
int res[100005][5];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x,y,z,cnt=1;
            cin>>x>>y>>z;
            res[i][1]=x,res[i][2]=y,res[i][3]=z;
            q2.push({i,1,1,x});
            q2.push({i,2,2,y});
            q2.push({i,3,3,z});
            while(!q2.empty())
            {
                int u=q2.top().u,dis=q2.top().dis;
                a[i][cnt]={u,dis};
                q2.pop();
                cnt++;
            }
            q.push({i,a[i][1].u,a[i][2].u,a[i][1].dis-a[i][2].dis});
            q.push({i,a[i][2].u,a[i][3].u,a[i][3].dis-a[i][3].dis});
        }
        while(!q.empty())
        {
            int id=q.top().id,u=q.top().u,v=q.top().v;
            q.pop();
            if(vis[id])
                continue;
            if(num[u]==n/2)
                continue;
            //cout<<id<<" "<<u<<" "<<v<<" "<<res[id][u]<<endl;
            ans+=res[id][u];
            vis[id]=1;
            num[u]++;
        }
        cout<<ans<<"\n";
        memset(num,0,sizeof(num));
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
    }
}
