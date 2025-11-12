#include <bits/stdc++.h>
using namespace std;

const int N=1e6+7;
typedef long long ll;

struct node{
    ll u,v,w;
};

ll f[N],n,m,k;
node edges[N];

ll found(ll x){
    if(f[x]==x) return x;
    return f[x]=found(f[x]);
}

void unite(ll x,ll y){
    ll fx=found(x),fy=found(y);
    f[fx]=fy;
}

bool cmp(node x,node y){
    return x.w<y.w;
}

ll kruskal(){
    ll ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        int u=edges[i].u,v=edges[i].v;
        if(found(u)!=found(v)){
            //cout<<u<<":"<<v<<endl;
            if(++cnt==n-1) break;
            f[found(u)]=found(v);
            ans+=edges[i].w;
        }
    }
    return (cnt==n-1?ans:-1);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n+10;i++)
        f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges+1,edges+m+1,cmp);
    cout<<kruskal()<<endl;
    //unite(1,2);
    //unite(2,3);
    //cout<<found(1)<<" "<<found(4);
    return 0;
}
/*
6 7
1 2 1
1 3 1
2 4 2
3 4 1
4 6 100
3 5 1
5 6 100
*/
