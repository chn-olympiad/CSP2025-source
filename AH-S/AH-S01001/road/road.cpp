#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
struct M{
    int f,t,w;
};
M e[N];
int n,m,k;
int c[101];
bool ca[101];
bool cmp(M a,M b){
    return a.w<b.w;
}
const int OO=1e5+1000;
int f[OO];
int fin(int x){
    return f[x]==x?x:f[x]=fin(f[x]);
}
int out=1e15;
int ku(){
    for(int i=1;i<=n+k;i++){
        f[i]=i;
    }
    int ans=0,op=0;
    for(int i=1;i<=k;i++){
        if(ca[i])ans+=c[i],op++;
    }
    int cnt=0;
    if(ans>out)return 1e15;
    for(int i=1;i<=m;i++){
        if(e[i].t>n){
            if(!ca[e[i].t-n])continue;
        }
        if(e[i].f>n){
            if(!ca[e[i].f-n])continue;
        }
        int x=fin(e[i].t);
        int y=fin(e[i].f);
        if(x!=y){
            f[x]=y;
            ans+=e[i].w;
            cnt++;
        }
        if(cnt==n+op-1)break;
    }
    return ans;
}

void dfs(int i){
    if(i==k+1){
        out=min(ku(),out);
        return;
    }
    ca[i]=0;
    dfs(i+1);
    ca[i]=1;
    dfs(i+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        e[i]={x,y,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            e[++m]={n+i,j,x};
        }
    }
    sort(e+1,e+1+m,cmp);
    dfs(1);
    cout<<out;
    return 0;
}