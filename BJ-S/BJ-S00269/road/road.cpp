#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct kl{
    int v,u,w;
}a[1000006];
bool cmp(kl p,kl q){
    return p.w<q.w;
}
ll fa[200005];
int down(int x){
    if(!fa[x])
        return x;
    return fa[x]=down(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    ll ans=0;
    cin>>n>>m>>k;
    if(k!=0){
        cout<<0;
        return 0;
    }
        
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<n;i++){
        int x=a[i].u,y=a[i].v;
        if(down(x)!=down(y)){
            fa[y]=down(x);
            ans+=a[i].w;
        }
    }
    cout<<ans;
}
