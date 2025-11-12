#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+10;
int h[N],e[M],ne[M],w[M],idx,s[N],pr[15],n,flag,v[N],fr[M];
queue<int>q;
vector<int> a[15];
set<int>siu,cris;
void add(int u,int v,int x)
{
    e[idx]=v;
    w[idx]=x;
    fr[idx]=u;
    ne[idx]=h[u];
    h[u]=idx++;
}
void bfs(int x)
{
    q.push(x);
    s[x]=0;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i])

        {
            int j=e[i];
            if(s[j]>=s[t]+w[i])
            {
                if(flag==1)cris.insert(fr[i]);
                else if(flag==2 and (j<=n or v[j]))siu.insert(idx);
                else
                {
                    q.push(j);
                    s[j]=min(s[j],s[t]+w[i]);
                    if(j>n)
                    {
                        for(int x:a[e[i]-n])w[x]-=pr[e[i]-n];
                        a[e[i]-n].clear();
                    }
                }
            }

        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(h,-1,sizeof h);
    memset(s,0x3f,sizeof s);
    int m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        add(u,v,x);
        add(v,u,x);
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;
        pr[i]=c;
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            a[i].push_back(idx);
            add(n+i,j,c+x);
            a[i].push_back(idx);
            add(j,n+i,c+x);
        }
    }
    bfs(1);
    flag=1;
    bfs(1);
    int ans=0;
    for(int x:cris)
    {
        if(x>n)ans+=pr[x-n];
        v[x]++;
        //cout<<x<<' ';
    }
    v[1]=1;
    flag=2;
    bfs(1);
    for(int x:siu)ans+=w[x];
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
