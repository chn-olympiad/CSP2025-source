#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20,M=1e6+10,K=13;
int n,m,k,c[K],a[K][N],f[N],citycost,ans=LONG_LONG_MAX,nowans,cst;
bool boo[K];
struct Edges{
    int u,v,w;
}s[12000010];
struct YWTD_DYCF{
    bool used[K];
    int val=LONG_LONG_MAX;
}dp[K];
bool pol_pot(Edges x,Edges y){return x.w<y.w;}
int find(int x){
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}
int kruskal(){
    cst=0;
    for(int i=1;i<=n+k;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        if((s[i].u>n&&boo[s[i].u-n]==false)||(s[i].v>n&&boo[s[i].v-n]==false)) continue;
        if(find(s[i].u)!=find(s[i].v)){
            cst+=s[i].w;
            f[find(s[i].u)]=f[find(s[i].v)];
        }
    }
    return cst;
}
/*void solve(){
    for(int i=1;i<=k;i++){
        boo[i]=true;
        citycost+=c[i];
        nowans=kruskal()+citycost;
        if(nowans>ans) {boo[i]=false;citycost-=c[i];}
        else ans=nowans;
    }
    //boo[1]=true,boo[2]=true;
    //cout<<kruskal()<<"\n";
    cout<<ans<<"\n";
    //cout<<citycost<<"\n";
    //cout<<boo[1]<<" "<<boo[2]<<"\n";
}*/
void solve2(){
    dp[0].val=kruskal();
    for(int i=1;i<=k;i++){
        for(int j=0;j<i;j++){
            citycost=0;
            for(int p=1;p<=k;p++) boo[p]=dp[j].used[p];
            boo[i]=true;
            for(int p=1;p<=k;p++) if(boo[p]==true) citycost+=c[p];
            nowans=kruskal()+citycost;
            if(nowans<dp[i].val){
                dp[i].val=nowans;
                for(int p=1;p<=k;p++) dp[i].used[p]=boo[p];
            }
        }
        for(int j=0;j<i;j++){
            nowans=dp[j].val;
            if(nowans<dp[i].val){
                dp[i].val=nowans;
                for(int p=1;p<=k;p++) dp[i].used[p]=dp[j].used[p];
            }
        }
    }
    cout<<dp[k].val;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {cin>>s[i].u>>s[i].v>>s[i].w;}
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) {cin>>a[i][j]; s[++m]={n+i,j,a[i][j]};}
    }
    sort(s+1,s+1+m,pol_pot);
    solve2();
    return 0;
}
