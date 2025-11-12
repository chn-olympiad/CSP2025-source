#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define pii pair<int,int>
#define fir first
#define sec second
#define P(x,y) make_pair(x,y)
#define ll long long
using namespace std;
bool BG;

const int maxn=2e4+5;
const int maxm=2e6+5;
const int maxk=13;
const ll INF=1e17;

int n,m,k,Etot,id[maxk],c[maxn],nw[maxk][maxn];
struct edge{
    int u,v,w;
    inline bool operator < (edge tmp) const{
        if (w!=tmp.w) return w<tmp.w;
        if (u!=tmp.u) return u<tmp.u;
        return v<tmp.v;
    }
}E[maxm],Etmp[maxm],cur[maxm];
int tot;
ll ans=INF;

int fa[maxn];
inline int find(int x){
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
inline ll calc(ll res){
    for (int i=1;i<=n+k;i++) fa[i]=i;

    sort(cur+1,cur+tot+1);

    for (int i=1;i<=tot;i++){
        int u=cur[i].u,v=cur[i].v,fu=find(u),fv=find(v);
        if (fu!=fv){
            fa[fu]=fv;
            res+=cur[i].w;
            if (res>ans) return res;
        }
    }

    return res;
}

inline int rd(){
    int x=0; char ch=getchar();
    while (ch<'0' || ch>'9'){
        ch=getchar();
    }
    while (ch>='0' && ch<='9'){
        x=(x<<3)+(x<<1)+(ch-'0');
        ch=getchar();
    }
    return x;
}

int lb[maxm],lg2[maxm];

bool ED;
int main(){
    fin("road.in");
    fout("road.out");

    n=rd(),m=rd(),k=rd();
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++){
        E[i].u=rd(),E[i].v=rd(),E[i].w=rd();
    }

    sort(E+1,E+m+1);
    for (int i=1;i<=m;i++){
        int u=E[i].u,v=E[i].v,fu=find(u),fv=find(v);
        if (fu!=fv){
            Etmp[++Etot]=E[i];
            fa[fu]=fv;
        }
    }
    for (int i=1;i<=Etot;i++) E[i]=Etmp[i];
    m=Etot;

    for (int i=1;i<=k;i++){
        c[i]=rd();
        for (int j=1;j<=n;j++) nw[i][j]=rd();
    }

    for (int i=2;i<=(1<<k);i++){
        lg2[i]=lg2[i>>1]+1;
    }
    for (int i=1;i<=(1<<k);i++){
        if (i&1) lb[i]=1;
        else lb[i]=(lb[i>>1]<<1);
    }

    for (int i=1;i<=m;i++) cur[i]=E[i];
    for (int S=0;S<(1<<k);S++){
        ll res=0;
        tot=m;
        for (int i=1;i<=m;i++) cur[i]=E[i];
        int i=S;
        while (i){
            int j=lg2[lb[i]]+1;
            for (int k=1;k<=n;k++){
                cur[++tot]=(edge){n+j,k,nw[j][k]};
            }
            res+=c[j];
            i-=lb[i];
        }
        if (res<ans) ans=min(ans,calc(res));
    }

    printf("%lld\n",ans);

    cerr<<"Memory : "<<1.0*(&ED-&BG)/1048576<<"Mb\n";
    return 0;
}
