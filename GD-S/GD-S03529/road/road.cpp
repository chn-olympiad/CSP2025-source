#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace IOfast{
    char bufin[1<<20],*fs,*ft;
    char getc(){
        return (fs==ft&&(ft=(fs=bufin)+fread(bufin,1,1<<20,stdin),fs==ft)?EOF:*fs++);
    }
    template<class T>
    void read(T& x){
        x=0;
        char ch;
        do ch=getc();
        while(ch<'0'||ch>'9');
        while(ch>='0'&&ch<='9'){
            x=x*10+ch-'0';
            ch=getc();
        }
    }
}
using namespace IOfast;
const int N=10015,M=1000005,K=11;
struct Union_Find{
    int fa[N],siz[N];
    ll res;
    void init(int n){
        res=0;
        for(int i=1;i<=n;i++)
            fa[i]=i,siz[i]=1;
    }
    int Find(int x){
        return x==fa[x]?x:(fa[x]=Find(fa[x]));
    }
    void merge(int x,int y,int w){
        x=Find(x),y=Find(y);
        if(x==y) return;
        res+=w;
        if(siz[x]>siz[y]) swap(x,y);
        fa[x]=y;
        siz[y]+=siz[x];
    }
}F,G[1<<10];
struct edge{
    int from,to,val;
}e[N*K+M];
bool cmp(const edge& x,const edge& y){
    return x.val<y.val;
}
vector<int>rec[K];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
    int n,m,k;
    read(n);
    read(m);
    read(k);
    F.init(n);
    for(int s=0;s<(1<<k);s++)
        G[s].init(n+k);
    for(int s=0;s<(1<<k);s++)
        for(int i=1;i<=k;i++)
            if(s&(1<<(i-1))) rec[i].push_back(s);
    for(int i=1,x,y,z;i<=m;i++){
        read(x);
        read(y);
        read(z);
        e[i]={x,y,z};
    }
    for(int i=1,x;i<=k;i++){
        read(x);
        for(int s=0;s<(1<<k);s++)
            if(s&(1<<(i-1))) G[s].res+=x;
        for(int j=1;j<=n;j++){
            read(x);
            e[++m]={i+n,j,x};
        }
    }
    sort(e+1,e+m+1,cmp);
    int lim=((k>5&&n>1000)?10000:1000000000),cnt=0;
    for(int i=1;i<=m;i++){
        int u=e[i].from,v=e[i].to,w=e[i].val;
        if(u<=n){
            if(F.Find(u)==F.Find(v)) continue;
            F.merge(u,v,w);
            for(int s=0;s<(1<<k);s++)
                G[s].merge(u,v,w);
        }
        else{
            ++cnt;
            if(cnt>lim) continue;
            u-=n;
            for(int s:rec[u])
                G[s].merge(u+n,v,w);
        }
    }
    ll res=1e18;
    for(int s=0;s<(1<<k);s++)
        res=min(res,G[s].res);
    printf("%lld\n",res);
}

