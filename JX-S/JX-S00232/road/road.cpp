#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
typedef long long ll;
typedef pair<int,int> PII;
struct edges{
    int v,w;
};
struct Node{
    int mw,p;
};
vector<edges>G[N];
ll c[20][N];
ll dis[N];
int cnt[20];
int n,m,k;
bool cmp(int x,int y){
    return x<y;
}
void dijistra(){
    priority_queue<PII,vector<PII>,greater<PII> >q;
    q.push({0,1});
    for(int i=1;i<=n;i++){
        dis[i]=2e9;
    }
    dis[1]=0;
    while(!q.empty()){
        PII x=q.top();
        q.pop();
        for(auto i:G[x.second]){
            if(dis[i.v]>i.w+x.first){
                dis[i.v]=i.w;
                q.push({x.first+dis[i.v],i.v});
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>c[i][j];
        }
    }
    dijistra();
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    for(int i=1;i<=k;i++){
        int mn=2e9,ls=0;
        for(int j=2;j<=n+1;j++){
            if(c[i][j]<mn){
                mn=c[i][j];
                ls=j;
            }
        }
        int cha=0;
        bool flag=1;
        for(int j=2;j<=n+1;j++){
            if(dis[j-1]>c[i][j]&&j!=ls){
                cha+=dis[j-1]-c[i][j];
            }
        }
        cha-=c[i][ls]+c[i][1];
        if(cha>0){
            ans=min(ans,ans-cha);
        }
    }
    cout<<ans;
    return 0;
}
