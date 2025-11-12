#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int,int>PII;
const int N=2e6+10,M=1e4+10;
int n,m,k;
int h[N],e[N],ne[N],w[N],idx,top;
struct node
{
    int a,b,w;
}edges[N];
int d[11][M],v[11];
int mp[1010][1010];
int p[N];int book[N],bak[N];
int st[N];
void add(int a,int b,int c)
{
    e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
int cmp(node a,node b){return a.w<b.w;}
int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int kruskal()
{
    sort(edges+1,edges+m+1,cmp);
    int res=0;
    for(int i=1;i<=top;i++)
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        a=find(a);b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=w;
        }
    }
    return res;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;top=m;
    memset(h,-1,sizeof h);memset(mp,0x3f,sizeof mp);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);add(b,a,c);
        edges[i]={a,b,c};
        mp[a][b]=mp[b][a]=min(mp[a][b],c);
    }
    for(int i=1;i<=n;i++)p[i]=i;
    int chkA=1;
    for(int i=1;i<=k;i++)
    {
        cin>>v[i];
        if(v[i])chkA=0;
        for(int j=1;j<=n;j++)
            cin>>d[i][j];
        int boo=0;
        for(int j=1;j<=n;j++)
            if(!d[i][j])boo=1;
        if(!boo)chkA=0;
    }
    if(!k)
    {
        cout<<kruskal()<<endl;
        return 0;
    }
    if(chkA)
    {
        cout<<11111<<endl;
        top=m;
        int res=0;
        for(int i=1;i<=k;i++)
        {
            int id=0;
            for(int j=1;j<=n;j++)
                if(d[i][j]==0)
                    id=j;
            for(int j=1;j<=n;j++)
            {
                if(id==j)continue;
                int val=d[i][j];
                edges[++top]={id,j,val};
            }
        }
        cout<<kruskal()<<endl;
    }
    return 0;
}
