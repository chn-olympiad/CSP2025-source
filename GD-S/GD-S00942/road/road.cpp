#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>

#define LL long long
#define pLL pair<LL,LL>

using namespace std;

void FileIO(string File) {
    freopen((File+".in").c_str(),"r",stdin);
    freopen((File+".out").c_str(),"w",stdout);
}
LL read() {
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

const LL K=15;
const LL N=1e4+5;
const LL M=1e6+5;

LL n,m,k;
LL ans=1e18;
LL c[K];
LL a[K][N];

struct Edge {
    LL u,v,w;
    LL bel;
} e[M+K*N];

LL fa[N];
void intt() {
    for(int i=1;i<=n;i++) {
        fa[i]=i;
    }
}
LL find(LL x) {
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
void merge(LL x,LL y) {
    x=find(x),y=find(y);
    if(x==y) return ;
    fa[x]=y;
}

int main() {
    FileIO("road");
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) {
        e[i].u=read(),e[i].v=read(),e[i].w=read();
        e[i].bel=0;
    }
    for(int i=1;i<=k;i++) {
        c[i]=read();
        for(int j=1;j<=n;j++) {
            a[i][j]=read();
            e[m+(i-1)*n+j].u=n+i;
            e[m+(i-1)*n+j].v=j;
            e[m+(i-1)*n+j].w=a[i][j];
            e[m+(i-1)*n+j].bel=i;
        }
    }
    m+=n*k;
    sort(e+1,e+1+m,[](Edge x,Edge y) {
        return x.w<y.w;
    });
    // for(int i=1;i<=m;i++) {
    //     printf("%lld %lld %lld %lld\n",e[i].u,e[i].v,e[i].w,e[i].bel);
    // }
    for(int i=0;i<(1<<k);i++) {
        LL tot=0;
        LL sum=0;
        LL getk=0;
        for(int j=0;j<k;j++) {
            if((i>>j)&1) {
                getk++;
                sum+=c[j+1];
            }
        }
        intt();
        for(int j=1;j<=m;j++) {
            LL u=e[j].u,v=e[j].v,w=e[j].w,bel=e[j].bel;
            if(find(u)==find(v)||(e[j].bel&&(((i>>(e[j].bel-1))&1)==0))) continue;
            sum+=w;
            merge(u,v);
            tot++;
            if(tot==n-1+getk) break;
        }
        // printf("%lld\n",sum);
        ans=min(ans,sum);
    }
    // LL tot=0;
    // intt();
    // for(int i=1;i<=n;i++) {
    //     LL u=e[i].u,v=e[i].v,w=e[i].w;
    //     if(find(u)==find(v)) continue;
    //     ans+=w;
    //     merge(u,v);
    //     tot++;
    //     if(tot==n-1) break;
    // }
    printf("%lld\n",ans);
    return 0;
}