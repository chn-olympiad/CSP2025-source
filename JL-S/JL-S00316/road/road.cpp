#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,t[15][10005],bel[1000005],ans;
struct node{
    ll u,v,w;
}r[1000005];
bool cmp(node p,node q){
    return p.w<q.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>r[i].u>>r[i].v>>r[i].w;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) cin>>t[i][j];
    }
    sort(r+1,r+m+1,cmp);
    ll cnt=1,i=1;
    while(cnt<n){
        if(bel[r[i].u]!=bel[r[i].v]||(!bel[r[i].u])&&(!bel[r[i].v])){
            ans+=r[i].w;
            bel[r[i].u]=1;
            bel[r[i].v]=1;
            cnt++;
        }
        i++;
    }
    cout<<ans<<'\n';
    return 0;
}
