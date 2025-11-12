#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T&x){
        x=0;char c=getchar();bool f=0;while(!isdigit(c)) c=='-'?f=1:0,c=getchar();
        if(f) while(isdigit(c)) x=x*10-(c-'0'),c=getchar();
        else while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
    }
    template<typename T>inline void write(T x){
        if(x==0){putchar('0');return ;}short st[50],top=0;
        if(x<0){putchar('-');while(x) st[++top]=-(x%10),x/=10;}
        else while(x) st[++top]=x%10,x/=10;while(top) putchar(st[top--]+'0');
    }
    inline void read(char&x){x=getchar();while(isspace(x)) x=getchar();}
    inline void write(char x){putchar(x);}
    inline void read(string&s){s.clear();char c;read(c);while(!isspace(c)&&~c) s+=c,c=getchar();}
    inline void write(string s){for(int i=0,len=s.size();i<len;i++) putchar(s[i]);}
    template<typename T>inline void write(T*x){while(*x) putchar(*x++);}
    template<typename T,typename...T2>inline void read(T&x,T2&...y){read(x),read(y...);}
    template<typename T,typename...T2>inline void write(const T x,const T2...y){write(x),putchar(' '),write(y...),sizeof...(y)==1?putchar('\n'):0;}
}using namespace IO;
#define ll long long
const int maxn=10020,maxm=1000020,maxk=20;
const ll inf=10000000000000;
int n,m,k,cnt,c[maxk],cs;
ll out=inf;
class DSU{
private:
    int fa[maxn+10];
public:
    int find_root(int u){return fa[u]==0?u:fa[u]=find_root(fa[u]);}
    void merge(int u,int v){u=find_root(u),v=find_root(v),fa[u]=v;}
    void clear(){memset(fa,0,sizeof(fa));}
}t;
struct EDGE{int u,v,w;bool operator<(const EDGE t){return w<t.w;}}a[maxm],base[maxn],gz[maxk][maxn],px[maxn*11],xpx[maxn*11];
void merge(int id){
    int w1=1,w2=1,xlen=0;
    while(px[w1].u&&gz[id][w2].u){
        if(px[w1]<gz[id][w2]) xpx[++xlen]=px[w1],w1++;
        else xpx[++xlen]=gz[id][w2],w2++;
    }
    while(px[w1].u) xpx[++xlen]=px[w1],w1++;
    while(gz[id][w2].u) xpx[++xlen]=gz[id][w2],w2++;
    swap(px,xpx);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n,m,k);for(int i=1;i<=m;i++) read(a[i].u,a[i].v,a[i].w);sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        int u=a[i].u,v=a[i].v;
        u=t.find_root(u),v=t.find_root(v);
        if(u==v) continue;
        t.merge(u,v),base[++cnt]=a[i];
    }
    for(int i=1;i<=k;i++){
        read(c[i]);
        for(int j=1;j<=n;j++) read(gz[i][j].w),gz[i][j].u=i+n,gz[i][j].v=j;
        sort(gz[i]+1,gz[i]+1+n);
    }
    for(int i=0;i<(1<<k);i++){
        ll ans=0;
        for(int j=1;j<=cnt;j++) px[j]=base[j];
        for(int j=1;j<=10;j++) if(i&(1<<(j-1))) merge(j),ans+=c[j];
        t.clear();
        for(int j=1;px[j].u;j++){
            int u=px[j].u,v=px[j].v;
            u=t.find_root(u),v=t.find_root(v);
            if(u==v) continue;
            t.merge(u,v),ans+=px[j].w;
        }
        for(int j=1;px[j].u;j++) px[j].u=0;
        out=min(out,ans);
    }
    write(out);
    return 0;
}
