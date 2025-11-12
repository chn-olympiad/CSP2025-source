#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int n,m,k;
struct node{
    int u,v,w;
}e[1000005],et[2000005],ew[2000005],ett[2000005];
int a[15][10005];
int cnt=0,cntt=0;
int c[15];
bool cmp(node x,node y){
    return x.w<y.w;
}
int f[10015];
int fd(int x){
    if(x==f[x]) return x;
    return f[x]=fd(f[x]);
}
void kruskal(){
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int fu=fd(e[i].u),fv=fd(e[i].v);
        if(fu!=fv){
            f[fu]=fv;
            ett[++cnt]=e[i];
        }
    }
}
int x[70005],y[70005],tt[70005];
void qsort(){
    for(int i=0;i<=65535;i++) tt[i]=0;
    for(int i=1;i<=cntt;i++){
        x[i]=et[i].w&65535;
        tt[x[i]]++;
    }
    for(int i=1;i<=65535;i++) tt[i]+=tt[i-1];
    for(int i=cntt;i>=1;i--) y[tt[x[i]]--]=i;
    for(int i=0;i<=65535;i++) tt[i]=0;
    for(int i=1;i<=cntt;i++){
        x[i]=(et[i].w/65536)&65535;
        tt[x[i]]++;
    }
    for(int i=1;i<=65535;i++) tt[i]+=tt[i-1];
    for(int i=cntt;i>=1;i--) ew[tt[x[y[i]]]--]=et[y[i]];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    sort(e+1,e+1+m,cmp);
    kruskal();
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++){
        cntt=cnt;
        ll res=0;
        for(int j=1;j<=cnt;j++){
            et[j]=ett[j];
        }
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1))){
                res+=c[j];
                for(int x=1;x<=n;x++){
                    et[++cntt]={n+j,x,a[j][x]};
                }
            }
        }
        // cerr<<cntt<<"\n";
        // sort(et+1,et+1+cntt,cmp);
        // for(int j=1;j<=cntt;j++) ew[j]=et[j];
        qsort();
        // for(int j=2;j<=cntt;j++){
        //     if(ew[j].w<ew[j-1].w) assert(0);
            // cout<<ew[j].u<<" "<<ew[j].v<<" "<<ew[j].w<<"\n";
        // }
        // cout<<"\n";
        for(int j=1;j<=n+k;j++) f[j]=j;
        for(int j=1;j<=cntt;j++){
            int fu=fd(ew[j].u),fv=fd(ew[j].v);
            if(fu!=fv) f[fu]=fv,res+=(ll)ew[j].w;
        }
        ans=min(ans,res);
        // cout<<res<<"\n";
    }
    cout<<ans<<'\n';
    return 0;
}