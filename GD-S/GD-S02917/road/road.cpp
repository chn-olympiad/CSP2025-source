#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int n,m;
int k;
int s[210];
int a[210][21000];
vector<PII>mp[21000];
priority_queue<PII,vector<PII>,greater<PII>>pq;
int val[21000];
int vis[21000];
int viss[21000];
int ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        mp[x].push_back({z,y});
        mp[y].push_back({z,x});
    }
    for(int i=1;i<=k;i++){
        cin>>s[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    memset(val,0x3f,sizeof(val));
    val[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        PII k=pq.top();
        pq.pop();
        if(vis[k.second]==1)continue;
        vis[k.second]=1;
        for(int i=0;i<mp[k.second].size();i++){
            PII x=mp[k.second][i];
            if(vis[x.second])continue;
            if(val[x.second]>k.first+x.first){
                val[x.second]=k.first+x.first;
                pq.push({val[x.second],x.second});
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,val[i]);
    }
    cout<<ans;
    return 0;
}