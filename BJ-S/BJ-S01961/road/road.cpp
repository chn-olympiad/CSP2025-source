#include<bits/stdc++.h>
namespace akioi
{
    using namespace std;
    #define F(i,x,y) for(i=x;i<=y;i++)
    #define rF(i,x,y) for(i=x;i>=y;i--)
    #define int long long
    void cout_better()
    {
        ios::sync_with_stdio(0);
        cout.tie(0),cin.tie(0);
        return;
    }
    const int N=1e4+105;
}
using namespace akioi;
int n,m,k,f[N],sz[N];
struct Node
{
    int u,v,w;
};
vector<Node> e;
bool cmp(Node x,Node y) {return x.w<y.w;}
int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y)
{
    if(sz[x]>sz[y]) swap(x,y);
    f[x]=y,sz[y]+=sz[x];
    return;
}
void solve()
{
    cin>>n>>m>>k;
    int i,j,ans=0,cnt=1;
    F(i,1,n+k) f[i]=i,sz[i]=1;
    F(i,1,m) 
    {
        Node tmp;
        cin>>tmp.u>>tmp.v>>tmp.w;
        e.push_back(tmp);
    }
    F(i,1,k) 
    {
        int c;
        cin>>c;
        F(j,1,n) 
        {
            Node tmp;
            tmp.u=n+i,tmp.v=j;
            cin>>tmp.w;
            e.push_back(tmp);
        }
    }
    sort(e.begin(),e.end(),cmp);
    for(auto x:e)
    {
        if(cnt==n+k) break;
        int u=find(x.u),v=find(x.v),w=x.w;
        if(u==v) continue;
        ans+=w,cnt++;
        merge(u,v);
    }
    cout<<ans;
    return;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cout_better();
    int T=1;
    //cin>>T;
    while(T--) solve();
}