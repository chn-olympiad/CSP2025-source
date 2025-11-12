#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll maxn=2e6+5,inf=1e18;
ll n,m,k;
ll fa[maxn],id[maxn];
ll wei[15][400005];
struct edge{
    ll u,v,c,cur;
}E[maxn],inp[maxn],org[maxn];
bool operator <(edge a,edge b){
    return a.c<b.c;
}
void init(ll n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
ll Find(ll x){
    if(fa[x]==x)return x;
    else return fa[x]=Find(fa[x]);
}
ll MST(ll n,ll m){
    ll ans=0;
    init(n);
    sort(E+1,E+m+1);
    for(int i=1,j=0;i<=m && j<n-1;i++){
        ll fu=Find(E[i].u),fv=Find(E[i].v);
        if(fu==fv)continue;
        fa[fu]=fv;
        ans+=E[i].c;
        j++;
        id[j]=E[i].cur;
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>inp[i].u>>inp[i].v>>inp[i].c;
        inp[i].cur=i;
        E[i]=inp[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>wei[i][j];
        }
    }
    ll ans=MST(n,m);
    ll mxwei=0;
    for(int i=1;i<=n-1;i++){
        org[i]=inp[id[i]];
        mxwei=max(mxwei,inp[id[i]].c);
    }
    for(int i=1;i<(1<<k);i++){
        ll tot=0,pre=0,adver=n;
        for(int i=1;i<=n-1;i++){
            E[++tot]=org[i];
        }
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1))){
                pre+=wei[j][0];
                adver++;
                for(int l=1;l<=n;l++){
                    if(wei[j][l]>=mxwei)continue;
                    E[++tot]={adver,l,wei[j][l],0};
                }
            }
        }
        ans=min(ans,pre+MST(adver,tot));
    }
    cout<<ans<<"\n";
    return 0;
}