#include<bits/stdc++.h>
using namespace std;
#define maxn 10004
#define maxm 1000006
#define ll long long
#define frp freopen
#define  fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
    T res=0,f=1;char c;
    for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
    return res*f;
}
const ll inf=4e18;
int n,m,k,c[11],a[11][maxn],fa[maxn*11],tot;
ll ans,s;
bool vis[maxn];
struct line{
    int u,v,w;
    bool operator<(const line &b)const{
        return w<b.w;
    }
}l[maxm],p[maxm];
int find(int x){return fa[x]!=x?fa[x]=find(fa[x]):x;}
int main(){
    fio("road.in","road.out");
    int i,j;
    n=read(),m=read(),k=read();
    for(i=1;i<=n;++i)fa[i]=i;
    for(i=1;i<=m;++i)l[i].u=read(),l[i].v=read(),l[i].w=read();
    for(i=1;i<=k;++i){
        c[i]=read();
        for(j=1;j<=n;++j)a[i][j]=read();
    }
    sort(l+1,l+m+1);
    for(i=1;i<=m;++i)
    {
        int u=l[i].u,v=l[i].v,d=l[i].w;
        if(find(u)==find(v))continue;
        ans+=d;
        fa[find(u)]=find(v);
        p[++tot]={u,v,d};
    }
    for(i=1;i<n;++i)l[i]=p[i];
    for(i=1;i<(1<<k);++i)
    {
        tot=n-1;s=0;
        for(j=1;j<=tot;++j)p[j]=l[j];
        for(j=1;j<=k;++j)if(i>>(j-1)&1){
            s+=c[j];
            for(int t=1;t<=n;++t)p[++tot]={j+n,t,a[j][t]};
        }
        sort(p+1,p+tot+1);
        for(j=1;j<=n+k;++j)fa[j]=j;
        for(j=1;j<=tot;++j)
        {
            int u=p[j].u,v=p[j].v,d=p[j].w;
            if(find(u)==find(v))continue;
            s+=d;
            fa[find(u)]=find(v);
        }
        ans=min(ans,s);
    }
    printf("%lld",ans);
    return 0;
}