#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m,k;
int c[20],p[20][N],dist[N];
bool st[N]={0};
bool s[N]={0};
vector<pair<int,int> > a[N]; 
void dj(int x){
    dist[x]=0;
    priority_queue<pair<int,int> > q;
    q.push({0,1});
    st[x]=1;
    while (!q.empty())
    {
        auto y=q.top();
        int u=y.second;
        q.pop();
        for(auto h:a[u]){
            int w=h.first,v=h.second;
            if(st[v]) continue;
            q.push({w,v});
            st[v]=1;
            for(int i=1;i<=k;i++){
                dist[v]=dist[u]+w;
                if(dist[v]>=c[i]*(!s[i])+p[i][u]+p[i][v]+dist[u]){
                   // cout<<c[i]*(!s[i])+p[i][u]+p[i][v]<<' ';
                    dist[v]=dist[u]+c[i]*(!s[i])+p[i][u]+p[i][v];
                    s[i]=1;
                }
            }
        }
        
    }
    
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dist,0x3f,sizeof(dist));
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=n;i++){
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>p[i][j];
    }
    dj(1);
    //for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
    cout<<dist[n]*2+1;
    return 0;
}