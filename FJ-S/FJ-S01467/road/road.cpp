#include<bits/stdc++.h>
#define ep emplace
#define eb emplace_back
#define fr(i,l,r) for(int i(l),_##i(r);i<=_##i;i++)
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
template<class T>inline T rd(T&x){
    bool f=1;T a=0;char c=getchar_unlocked();
    for(;c<'0'||c>'9';c=getchar_unlocked())f&=c!='-';
    for(;c>='0'&&c<='9';c=getchar_unlocked())a=c-'0'+a*10;
    return x=f?a:-a;
}template<class T,class...U>inline void rd(T&x,U&...y){rd(x),rd(y...);}
using namespace std;using ll=long long;using ull=unsigned long long;
const int N=1e4+13,M=1e5+1e4+3;
int n,m,k,u,v,w,c[13],fa[N],cnt,tot;ll ans;
struct E {
    int u,v,w;
    inline bool operator<(const E&b)const{return w<b.w;}
}e[N*100],ee[N],a[13][N],f[M];

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool merge(int x,int y){
    x=find(x),y=find(y);
    return x^y?fa[x]=y,1:0;
}

inline void merge(E*a,int x,E*b,int y){
    static E c[M];
    int j=0,t=0;
    fr(i,1,y){
        while(j<x&&a[j+1]<b[i])c[++t]=a[++j];
        c[++t]=b[i];
    }while(j<x)c[++t]=a[++j];
    fr(i,1,x+y)a[i]=c[i];
}

int main(){
    file(road);
    rd(n,m,k);
    fr(i,1,m)rd(u,v,w),e[i]={u,v,w};
    fr(i,1,k){
        rd(c[i]);
        fr(j,1,n)rd(w),a[i][j]={n+i,j,w};
        sort(a[i]+1,a[i]+n+1);
    }
    iota(fa+1,fa+n+1,1),sort(e+1,e+m+1);
    fr(i,1,m)if(merge(e[i].u,e[i].v)){
        ee[++cnt]=e[i],ans+=e[i].w;
        if(cnt==n-1)break;
    }
    int full=(1<<k)-1;
    fr(S,1,full){
        ll s=0;tot=cnt;
        fr(i,1,cnt)f[i]=ee[i];
        fr(i,1,k)if(S>>i-1&1)s+=c[i],merge(f,tot,a[i],n),tot+=n;
        iota(fa+1,fa+n+k+1,1);
        bool fl=s>=ans;
        fr(i,1,tot)if(merge(f[i].u,f[i].v)){
            s+=f[i].w;
            if(s>=ans){fl=1;break;}
        }if(!fl)ans=min(ans,s);
    }
    return cout<<ans,0;
}