#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1100001

struct edge{
    ll x,y,z;
};
bool operator<(edge x,edge y){
    return x.z<y.z;
}

ll n,m,k;
ll v[11],b[11];
ll fa[SIZE];
edge f[SIZE];

ll gets(ll x){
    if(fa[x]!=x) fa[x]=gets(fa[x]);
    return fa[x];
}

ll dfs(ll now){
    if(now>k){
        ll res=0,sz=n+k;
        for(ll i=1;i<=k;i++){
            if(!b[i]) sz--;
            res+=b[i]*v[i];
        }
        for(ll i=1;i<=n+k;i++) fa[i]=i;
        for(ll i=1;i<=m;i++){
            if(f[i].x>n&&(!b[f[i].x-n])) continue;
            ll x=gets(f[i].x);
            ll y=gets(f[i].y);
            if(x!=y){
                fa[x]=y;
                res+=f[i].z;
                if((--sz)==1) break;
            }
        }
        return res;
    }
    b[now]=1;
    ll res=dfs(now+1);
    b[now]=0;
    if(v[now]) res=min(res,dfs(now+1));
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++)
    cin>>f[i].x>>f[i].y>>f[i].z;
    for(ll i=1;i<=k;i++){
        cin>>v[i];
        for(ll j=1;j<=n;j++){
            ll cost;
            cin>>cost;
            f[++m]={n+i,j,cost};
        }
    }
    sort(f+1,f+m+1);
    cout<<dfs(1);
    return 0;
}