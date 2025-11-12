#include <bits/stdc++.h>
#define ll long long
#define MAN 11451400
#define INF 1e18
using namespace std;
ll n,m,k,cnt;
struct edge{
    ll u,v,w;
}a[MAN];
ll fa[MAN],ans;
ll c[MAN];
ll find1(ll x){
    if(fa[x]=x) return x;
    else return fa[x]=find1(fa[x]);
}
ll init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
void merge(ll x,ll y){
    ll o=find1(x);
    fa[o]=find1(y);
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
void kruscal(){
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(find1(a[i].u)!=find1(a[i].v)){
            merge(a[i].u,a[i].v);
            cnt--;
            ans+=a[i].w;
        }
        if(cnt==1) break;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    cnt=n;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    init();
    kruscal();
    cout<<ans<<endl;
    return 0;
}
