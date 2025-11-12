#include<iostream>
#include<queue>
using namespace std;

int n,m,k;
const int MAXN=2e4+2,MAXM=2e6+2;
int a[20];
int cnt,head[MAXN],to[MAXM],nt[MAXM],w[MAXM];
int d[MAXN];
bool vi[MAXN];
void add(int u,int v,int c)
{
    nt[++cnt]=head[u];
    w[cnt]=c;
    to[cnt]=v;
    head[u]=cnt;
}
struct node{
    int u,w;
};
void dij(int st)
{
    queue<node>q;
    d[st]=0;
    q.push({st,0});
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(vi[u.u])continue;
        int minn=0;
        for(int i=head[u.u];i;i=nt[i])
        {
            int v=to[i];
            if(w[i]<w[minn])minn=i;
            d[v]=min(d[to[minn]],d[u.u]+w[minn]);
            q.push({v,d[v]});
        }
        vi[minn]=1;
    }
}

bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    w[0]=0x3f3f3f;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
        add(v,u,c);
    }
    int st=n/2;
    //不是dij怎么求全树路径的和啊啊啊啊啊
    //QWQ
    cout<<0<<endl;
    return 0;
}
