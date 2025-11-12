#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10001],b[11][10001],c[11];
bool e[11];
struct r{
    long long u,v,w;
}a[1000001];
inline bool cmp(r x,r y){
    return x.w<y.w;
}
inline void into(long long n){
    for(long long i=1;i<=n;++i){
        fa[i]=i;
    }
}
inline long long fin(long long x){
    if(fa[x]==x)return x;
    return fa[x]=fin(fa[x]);
}
inline void in(long long x,long long y){
    if(fin(x)!=fin(y))
        fa[x]=fin(y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    into(n);
    for(long long i=0;i<m;++i){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a,a+m,cmp);
    long long cut=0,ans=0;
    for(long long i=0;cut<n-1;++i){
        if(fin(a[i].u)!=fin((a[i].v))){
            ++cut;
            ans+=a[i].w;
        }
    }
    cout<<ans;
    return 0;
}
