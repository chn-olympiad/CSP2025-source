#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read();
void write(ll x);
const int N=1e5+10,M=2e6+10,K=15;
int n,m,k;
int tot;
struct Node{
    int u,v,w;
    bool operator <(const Node &t)const{
        return w>t.w;
    }
}edge[M];
int p[N];
int c[K];
int a[K][N];
int id[N];
int deg[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
ll kruskal(int nn){
    for(int i=1;i<=nn;i++) p[i]=i;
    priority_queue<Node> q;
    for(int i=1;i<=tot;i++){
        q.push({edge[i].u,edge[i].v,edge[i].w});
    }
    int cnt=0;
    ll ans=0;
    while(cnt<nn-1){
        auto hh=q.top();
        q.pop();
        int u=hh.u,v=hh.v,w=hh.w;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            cnt++;
            if(id[u]&&id[v]&&id[u]==id[v]){
                for(int j=1;j<=n;j++){
                    q.push({n+id[u],j,a[id[u]][j]});
                }
            }
            deg[u]++,deg[v]++;
            ans+=w;
            p[fu]=fv;
        }
    }
    return ans;
}
int main(){
    //update file name!!!
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        edge[++tot]={read(),read(),read()};
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        id[n+i]=id[n+k+i]=i;
        edge[++tot]={n+i,n+k+i,c[i]};
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    ll ans=kruskal(n+k*2);
    for(int i=1;i<=k;i++){
        if(deg[n+i]>2) continue;
        int minn=2e9;
        for(int j=1;j<=n;j++){
            minn=min(minn,a[i][j]);
        }
        ans=ans-minn-c[i];
    }
    write(ans);
    return 0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(ll x){
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+'0');
}