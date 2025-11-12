#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
const int MAXM=1e6+10;
const int MAXK=12;
struct Edge{
    int u,v;
    ll val;
}e[MAXM];
ll minl[MAXN][MAXN],w[MAXN][MAXN];
int n,m,k,tot;
ll c[MAXK],a[MAXK][MAXN];
bool cmp(Edge x,Edge y){
    return x.val<y.val;
}
struct Dsu{
    int fa[MAXN];
    void Init(int x){
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
    }
    int Find(int x){
        return fa[x]==x?x:fa[x]=Find(fa[x]);
    }
}tr;
bool flag[MAXK];
ll ans=1e10;
void Work(){
    memcpy(minl,w,sizeof(w));
    ll tmp=0;
    for(int i=1;i<=k;i++){
        if(flag[i]==0){
            continue;
        }
        tmp+=c[i];
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u==v){
                    continue;
                }
                minl[u][v]=min(minl[u][v],a[i][u]+a[i][v]);
            }
        }
    }
    tot=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(minl[i][j]<1e10){
                e[++tot]={i,j,minl[i][j]};
            }
        }
    }
    sort(e+1,e+tot+1,cmp);
    tr.Init(n);
    for(int i=1;i<=tot;i++){
        int u=e[i].u,v=e[i].v;
        ll val=e[i].val;
        u=tr.Find(u);
        v=tr.Find(v);
        if(u==v){
            continue;
        }
        tr.fa[v]=u;
        tmp+=val;
    }
    ans=min(ans,tmp);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    srand(time(NULL));
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    // cout<<minl[0][0]<<endl;
    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=m;i++){
        int u,v;
        ll val;
        cin>>u>>v>>val;
        w[u][v]=min(w[u][v],val);
        w[v][u]=min(w[v][u],val);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    Work();
    for(int i=1;i<=k;i++){
        flag[i]=1;
    }
    Work();
    for(int i=1;i<=7;i++){
        for(int j=1;j<=k;j++){
            flag[j]=rand()&1;
        }
        Work();
    }
    cout<<ans<<endl;
    return 0;
}