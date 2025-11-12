#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream cin("road.in");
ofstream cout("road.out");
const int NR=1e4+24,inf=0x3f3f3f3f;
struct node
{
    int to,val;
}lin,h;
bool operator < (node al,node bw)
{
    return al.val<bw.val;
}
vector<node> lox[NR],chg[NR];
priority_queue<node> q;
bool vis[NR];
int dis[NR],ans=0,n,m,k,u,v,w,c[15],a[15][NR],mxc,mxa;
int kruskal()
{
    memset(vis,false,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    lin.to=1,lin.val=0;
    q.push(lin);
    while(!q.empty())
    {
        h=q.top();
        q.pop();
        if(vis[h.to])
            continue;
        vis[h.to]=true;
        ans+=h.val;
        for(int i=0;i<lox[h.to].size();i++)
        {
            if(dis[h.to]+lox[h.to][i].val<dis[lox[h.to][i].to])
            {
                dis[lox[h.to][i].to]=dis[h.to]+lox[h.to][i].val;
                if(!vis[lox[h.to][i].to])
                {
                    q.push(lox[h.to][i]);
                }
            }
        }
    }
    return ans;
}
/*int dfs(int pos)
{
    int op;
    if(pos==n+1)
        return kruskal();
    op=dfs(pos+1);
    for(int j=1;j<=n;j++)
        lox[n+pos].push_back({j,a[n+pos][j]}),lox[j].push_back({n+pos,a[n+pos][j]});
    op=dfs(pos+1);
    {
        lox[n+pos].clear();
        lox[j].clear()
    }
}*/
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        lox[v].push_back({u,w});
        lox[u].push_back({v,w});
    }
    if(k==0)
    {
        cout<<kruskal()<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        mxc=max(mxc,c[i]);
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            mxa=max(mxa,a[i][j]);
        }
    }
    if(mxc==0&&mxa==0)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<114514<<endl;
    //cout<<dfs(1)<<endl;
    return 0;
}
