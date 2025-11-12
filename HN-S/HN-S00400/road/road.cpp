#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int k=1,s=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') k=-k;
    for(;isdigit(c);c=getchar()) s=(s<<1)+(s<<3)+(c^48);
    return k*s;
}
//不行了，必须开T2了，不然真炸了
const int K=14;
const int N=1e4+5;
const int M=1e6+5;
struct edge{
    int u,v,w;
    bool operator<(const edge &tmp)const{
        return w<tmp.w;
    }
}e[M<<2];
int n,m,k,c[K],a[K][N],f[N],vis[N];
int find(int x){
    return f[x]==x ? x : f[x]=find(f[x]);
}
void wk0(){
    for(int i=1;i<=n;++i) f[i]=i;
    int cnt=0,ans=0;
    sort(e+1,e+1+m);
    for(int i=1;i<=m;++i){
        int a=find(e[i].u),b=find(e[i].v);
        // printf("u=%lld,v=%lld,w=%lld\n",e[i].u,e[i].v,e[i].w);
        if(a!=b){
            f[a]=b;
            ans+=e[i].w;
            ++cnt;
            if(cnt==n-1) break;
        }
    }
    // for(int i=1;i<=n;++i) cout<<f[i]<<' ';cout<<'\n';
    cout<<ans<<'\n';
}
void wk2(){
    int cnt=0,ans=0;
    for(int i=1;i<=k;++i){
        ans+=c[i];
        for(int j=1;j<=n;++j){
            e[++m]={n+i,j,a[i][j]};
            // cerr<<"m="<<m<<'\n';
        }
    }
    for(int i=1;i<=n;++i) f[i]=i;
    sort(e+1,e+1+m);
    int res=n;
    for(int i=1;i<=m;++i){
        int a=find(e[i].u),b=find(e[i].v);
        // printf("u=%lld,v=%lld,w=%lld\n",e[i].u,e[i].v,e[i].w);
        if(a!=b){
            // if(e[i].u>n && !vis[e[i].u]) res++,vis[e[i].u]=1; 
            f[a]=b;
            ans+=e[i].w;
            ++cnt;
            int x=find(1),tag=1;
            for(int i=2;i<=n;++i){
                if(x!=find(i)) tag=0;
            }
            if(tag) break;
        }
    }
    // for(int i=1;i<=n;++i) cout<<f[i]<<' ';cout<<'\n';
    cout<<ans<<'\n';
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read(); k=read();
    for(int i=1;i<=m;++i){
        e[i].u=read(); e[i].v=read(); e[i].w=read();
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j) a[i][j]=read();
    }
    if(k==0){ 
        wk0();
        return 0;
    }
    else{
        wk2();
        return 0;
    }
    return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/