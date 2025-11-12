#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
int read()
{
    int r=0,f=1;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) r=(r<<1)+(r<<3)+c-48,c=getchar();
    return r;
}
const int N=5e6+5;
int n,m,k;
struct node
{
    int x,y;
    ll w;
}pos[N],dpos[11][10005],Spos[200005];
int cnt;
ll v[11];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct Node
{
    int i,j;
};
bool operator <(Node a,Node b){ return dpos[a.i][a.j].w>dpos[b.i][b.j].w; }
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cin>>n>>m>>k;
    n=read(); m=read(); k=read();
    for(int i=1;i<=m;i++)
        pos[i].x=read(),pos[i].y=read(),pos[i].w=read();
        // cin>>pos[i].x>>pos[i].y>>pos[i].w;
    sort(pos+1,pos+1+m,[](node a,node b){return a.w<b.w;});
    for(int i=1;i<=k;i++)
    {
        // cin>>v[i];
        v[i]=read();
        for(int j=1;j<=n;j++)
            dpos[i][j]=node{i+n,j,read()};
            // cin>>dpos[i][j].w;
        sort(dpos[i]+1,dpos[i]+1+n,[](node a,node b){return a.w<b.w;});
    }
    iota(fa+1,fa+1+n,1);
    int pcnt=n;
    for(int i=1;i<=m;i++)
    {
        int nx=find(pos[i].x),ny=find(pos[i].y);
        if(nx==ny) continue;
        dpos[0][++cnt]=pos[i];
        fa[nx]=ny; pcnt--;
        if(pcnt==1) break;
    }
    ll ans=2e18;
    priority_queue<Node> q;
    for(int S=0;S<(1<<k);S++)
    {
        while(!q.empty()) q.pop();
        q.push(Node{0,1});
        int kcnt=0; ll nans=0;
        // for(int i=1;i<=cnt;i++)
        //     Spos[++kcnt]=dpos[0][i];
        for(int j,T=S;T;T^=1<<j)
        {
            j=__lg(T); nans+=v[j+1]; q.push(Node{j+1,1});
            // for(int i=1;i<=n;i++)
            //     Spos[++kcnt]=dpos[j+1][i];
            if(nans>ans) break;
        }
        // cerr<<'?';
        // sort(Spos+1,Spos+1+kcnt,[](node a,node b){return a.w<b.w;});
        iota(fa+1,fa+1+n+k,1);
        int pcnt=n+__builtin_popcount(S);
        // for(int i=1;i<=kcnt;i++)
        while(!q.empty())
        {
            Node dx=q.top(); q.pop();
            node p=dpos[dx.i][dx.j];
            if((dx.i==0&&dx.j<cnt)||dx.j<n)
                dx.j++,q.push(dx);
            int nx=find(p.x),ny=find(p.y);
            if(nx==ny) continue;
            fa[nx]=ny; pcnt--; nans+=p.w;
            if(nans>ans) break;
            // if(S==1) cerr<<Spos[i].x<<' '<<Spos[i].y<<' '<<Spos[i].w<<'\n';
            if(pcnt==1) break;
        }
        // if(nans==12)
        // {
        //     cout<<S<<'\n';
        // }
        ans=min(ans,nans);
    }
    cout<<ans<<'\n';
}