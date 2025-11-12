#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k,cnt;
struct node{
    int u,v,w;
    bool operator<(const node &o)const{return w<o.w;}
}e[M],t[M];
int fa[N],siz[N],ans;
int c[N],a[12][N];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    n=read();m=read();k=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        e[i]=(node){u,v,w};
    }
    sort(e+1,e+1+m);
    int K=n;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fax=find(u),fay=find(v);
        if(fax==fay)continue;
        fa[fay]=fax;
        t[++cnt]=e[i];
        ans+=w;--K;if(K==1)break;
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j)a[i][j]=read();
    }
    m=0;
    for(int i=1;i<=cnt;++i){
        e[++m]=t[i];
    }
    cnt=0;
    for(int S=1;S<(1<<k);++S){
        cnt=0;
        int Z=n,tmp=0;
        for(int i=0;i<k;++i)if((S>>i)&1){
            ++Z;tmp+=c[i+1];
            for(int j=1;j<=n;++j)e[++cnt]={Z,j,a[i+1][j]};
        }
        for(int i=1;i<=m;++i)e[++cnt]=t[i];
        for(int i=1;i<=Z;++i)fa[i]=i,siz[i]=1;
        sort(e+1,e+1+cnt);
        int K=Z;
        for(int i=1;i<=cnt;++i){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            int fax=find(u),fay=find(v);
            if(fax==fay)continue;
            if(siz[fax]<siz[fay])swap(fax,fay);
            fa[fay]=fax;siz[fax]+=siz[fay];
            tmp+=w;--K;if(K==1)break;
        }
        ans=min(ans,tmp);
    }
    write(ans);
    return 0;
}
/*
diff -a -b road.out road4.ans
*/