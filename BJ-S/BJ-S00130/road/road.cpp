#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
const int N=10015;
struct Edge{
    int u,v;
    ll w;
    friend bool operator<(Edge x,Edge y){
        return x.w<y.w;
    }
};
int lowbit(int x){return x&(-x);}
vector <Edge>G[11],E[1030];
int n,m,k,fa[N];
ll ans,c[11];
int findfa(int x){
    if(fa[x]==x)return x;
    return fa[x]=findfa(fa[x]);
}
ll mst(int id,int pre,int now){
    vector <Edge>v;
    for(Edge e:G[now])v.push_back(e);
    for(Edge e:E[pre])v.push_back(e);
    sort(v.begin(),v.end());
    for(int i=1;i<=n+k;i++)fa[i]=i;
    ll res=0;
    for(Edge e:v){
        int u=e.u,v=e.v,w=e.w;
        int uu=findfa(u),vv=findfa(v);
        if(uu!=vv){
            E[id].push_back(e);
            fa[vv]=uu;
            res+=w;
        }
    }
    return res;
}
void dfs(int x,ll sum,int t){
    if(x==k+1){
        if(t==0)return ;
        int tmp=lowbit(t);
        int pos=k+1;
        while(tmp)tmp>>=1,pos--;
        ans=min(ans,mst(t,t-lowbit(t),pos)+sum);
        return ;
    }
    dfs(x+1,sum,t<<1);
    dfs(x+1,sum+c[x],t<<1|1);
}
int read(){
    int res=0;
    char ch=getchar();
    while(ch<'0'&&ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar();
    }
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    n=read(),m=read(),k=read();
    for(int i=1,u,v;i<=m;i++){
        ll w;
        u=read(),v=read(),w=read();
        E[1025].push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1,x;j<=n;j++){
            x=read();
            G[i].push_back({n+i,j,x});
        }
    }
    ans=mst(0,1025,0);
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}
