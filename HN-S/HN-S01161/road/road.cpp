// road
#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-f;
    for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
    return f*x;
}
const int N=1e4+4,M=1e6+5,K=15;
int n,m,k;
int h[N],cnt,to[M<<1],nxt[M<<1],w[M<<1];
void add(int u,int v,int l){
    to[++cnt]=v;
    w[cnt]=l;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
int c[K],a[K][N];
int f[N];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    f[find(y)]=find(x);
}
struct zjy{
    int u,v,w;
    bool operator<(const zjy &o)const{
        return w>o.w;
    }
};
priority_queue<zjy>q;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),l=read();
        add(u,v,l),add(v,u,l);
        q.push((zjy){u,v,l});
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    while(!q.empty()){
        int u=q.top().u;
        int v=q.top().v;
        int l=q.top().w;
        q.pop();
        if(find(u)!=find(v)){
            merge(u,v);
            ans+=1ll*l;
        }
    }
    printf("%lld",ans);
    return 0;
}