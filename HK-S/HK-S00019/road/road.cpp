#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,parent[100100];
ll c[100],b[15][100100]; bool done[100];
int findpa(ll a){
    if(parent[a]==a) return a;
    else return parent[a]=findpa(parent[a]);
}
priority_queue<tuple<ll,ll,ll,ll>,vector<tuple<ll,ll,ll,ll>>, greater<tuple<ll,ll,ll,ll>>> pq;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        parent[i]=i;
        ll u,v,w;
        cin>>u>>v>>w;
        pq.push({w,u,v,0});
    }
    for(ll i=1;i<=k;i++){
        cin>>c[i]; done[i]=0;
        for(ll j=1;j<=n;j++){
            cin>>b[i][j];
            for(ll k=1;k<j;k++){
                pq.push({b[i][k]+b[i][j]+c[i],k,j,i});
            }
        }
    }
    ll cnt=0,ans=0;
    while(!pq.empty()&&cnt<n){
        auto[w,u,v,nw]=pq.top(); pq.pop();
        parent[u]=findpa(u);
        parent[v]=findpa(v);
        if(parent[u]!=parent[v]){
            if(nw!=0) {
                if(!done[nw])w=b[nw][u]+b[nw][v]+c[nw];
                else w=b[nw][u]+b[nw][v];
                b[nw][u]=0;
                b[nw][v]=0;
                if(!done[nw]){
                    for(ll i=1;i<=n;i++){
                        for(ll j=1;j<i;j++){
                            pq.push({b[nw][i]+b[nw][j],i,j,nw});
                        }
                    }
                    done[nw]=1;
                }else{
                    for(ll i=1;i<=n;i++){
                        ll pi=findpa(i);
                        pq.push({b[nw][i],i,u,nw});
                        pq.push({b[nw][i],i,v,nw});
                    }
                }
            }
            ans+=w;
            cnt++;
            if(parent[v]<parent[u]) parent[parent[u]]=parent[v];
            else parent[parent[v]]=parent[u];
        }
    }
    cout<<ans<<endl;
return 0;
}
 /**/
