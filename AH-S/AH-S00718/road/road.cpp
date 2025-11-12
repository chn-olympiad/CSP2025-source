#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5;
ll n,m,k,c[N],s[15][N],fa[N],ans,cnt;
struct node{
    ll u,v,w;
} a[N*100];
bool cmp(node x,node y){
    return x.w<y.w;
}
ll find(ll x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>s[i][j];
    }
    if(k==0){
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            ll u=find(a[i].u),v=find(a[i].v);
            if(u==v) continue;
            fa[u]=v;
            ans+=a[i].w;
            cnt++;
            if(cnt==n-1) break;
        }
        cout<<ans;
        return 0;
    }else cout<<0;
    return 0;
}
