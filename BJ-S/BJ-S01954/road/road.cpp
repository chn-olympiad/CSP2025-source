#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
    ll u,v,w;
    bool operator<(const node&a)const{
        return w<a.w;
    }
};
ll fa[1000011],n,m,k,nn;
node a[1000011];
ll find(ll x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
void mer(ll x,ll y){
    ll fx=find(x),fy=find(y);
    fa[fy]=fx;
}
void add(ll u,ll v,ll w){
    a[++nn]={u,v,w};
}
bool connect(ll x,ll y){
    return find(x)==find(y);
}
bool cmp(node a,node b){
    return a.w<b.w;
}
ll kur(){
    priority_queue<node>pq;
    for(ll i=1;i<=n;++i){
        pq.push(a[i]);
    }
    ll cnt=0,last=-1,sum=0,xadd=0;
    bool flag=0;
    while(cnt<n-1){
        node x=pq.top();
        pq.pop();
        if(!connect(x.u,x.v)){
            mer(x.u,x.v);
            sum+=x.w;
            ++cnt;
        }
        last=sum;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=0;i<=n+k;++i){
        fa[i]=i;
    }
    for(ll i=1;i<=m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
   // for(ll i=1;i<=k;++i){
   //     ll c;
   //     cin>>c;
    //    add(0,i,c);
   //     for(ll j=1;j<=n;++j){
   //         ll w;
   //         cin>>w;
    //        add(i,j,w);
    //    }
    //}
    cout<<kur();
    return 0;
}
//Ren5Jie4Di4Ling5%