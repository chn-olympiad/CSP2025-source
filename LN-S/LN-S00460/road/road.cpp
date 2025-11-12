#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{ll s,e,w;};
const int N=1e4+20;
vector<edge>ed[N];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
ll nd[N],n,m,k,vis[N];
void work(){
    int ans=0;
    queue<int>q;
    q.push(1);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=0;i<ed[t].size();i++){
            edge tmp=ed[t][i];
            if(!vis[tmp.e]){
                vis[tmp.e]=tmp.w+nd[tmp.s];

                q.push(tmp.e);
            }
            else ed[t][i].e=min(tmp.e,tmp.w+nd[tmp.s]);
        }
    }
    for(int i=1;i<=n;i++)ans+=vis[i];
    cout<<ans<<endl;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    bool tmp=0;
    for(ll i=1;i<=m;i++){
        ll f,t,w;
        cin>>f>>t>>w;
        ed[f].push_back({f,t,w});
        ed[t].push_back({t,f,w});
    }
    for(ll i=1;i<=k;i++){
        ll c;
        cin>>c;
        nd[i+n]=c;
        if(c!=0)tmp=1;
        for(ll j=1;j<=n;j++){
            ll w;
            cin>>w;
            if(w!=0)tmp=1;
            ed[i+n].push_back({i+n,j,w});
            ed[j].push_back({j,i+n,w});
        }
    }
    if(tmp==0){
        cout<<"0\n";
        return 0;
    }
    work();
    return 0;
}
