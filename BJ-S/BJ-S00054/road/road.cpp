#include<bits/stdc++.h>
#define ll long long
void read(int &x){
    x=0;bool neg=0;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=1;c=getchar();}
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(neg)x=-x;
}
#define se second
#define fi first
#define read2(x,y) read(x),read(y)
#define read3(x,y,z) read2(x,y),read(z)
using namespace std;
int n,m,k;
struct edge{
    int u,v,w;
}e[2000005],e_[2000005],e__[2000005];
int a[11][10005],c[11];
struct dsu{
    int fa[200005];
    int fr(int x){
        return fa[x]?fa[x]=fr(fa[x]):x;
    }
    void mg(int x,int y){
        x=fr(x),y=fr(y);
        if(x==y)return;
        fa[x]=y;
    }
    void init(){
        for(int i=1;i<=n+k;i++)fa[i]=0;
    }
}D;
namespace subA{
    void slv(){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                e[++m]={n+i,j,a[i][j]};
            }
        }
        sort(e+1,e+1+m,[&](edge x,edge y){return x.w<y.w;});
        int ans=0;
        for(int i=1;i<=m;i++){
            if(D.fr(e[i].u)==D.fr(e[i].v))continue;
            D.mg(e[i].u,e[i].v);
            ans+=e[i].w;
        }
        cout<<ans<<endl;
    }
}
void slv(){
    read3(n,m,k);
    bool A=1;
    for(int i=1;i<=m;i++){
        read3(e[i].u,e[i].v,e[i].w);
    }
    for(int i=1;i<=k;i++){
        read(c[i]);
        if(c[i])A=0;
        bool c0=0;
        for(int j=1;j<=n;j++){
            read(a[i][j]);
            if(!a[i][j])c0=1;
        }
        if(!c0)A=0;
    }
    if(A){
        subA::slv();
        return;
    }
    sort(e+1,e+1+m,[&](edge x,edge y){return x.w<y.w;});
    int cnt=0;
    ll ans=0,sum=0;
    for(int i=1;i<=m;i++){
        if(D.fr(e[i].u)==D.fr(e[i].v))continue;
        D.mg(e[i].u,e[i].v);
        cnt++;
        e_[cnt]=e[i];
        ans+=e[i].w,sum+=e[i].w;
    }
    for(int i=1;i<(1<<k);i++){
        ll res=0;
        for(int j=1;j<=cnt;j++)e__[j]=e_[j];
        int tot=cnt;
        for(int j=1;j<=k;j++){
            if(i>>(j-1)&1){
                res+=c[j];
                for(int k=1;k<=n;k++){
                    e__[++tot]={j+n,k,a[j][k]};
                }
            }
        }
        sort(e__+1,e__+1+tot,[&](edge x,edge y){return x.w<y.w;});
        D.init();
        for(int i=1;i<=tot;i++){
            if(D.fr(e__[i].u)==D.fr(e__[i].v))continue;
            res+=e__[i].w;
            D.mg(e__[i].u,e__[i].v);
        }
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    slv();
}