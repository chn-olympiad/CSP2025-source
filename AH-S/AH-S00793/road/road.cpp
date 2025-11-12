#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,mp[10005];
vector<pair<int,int> > a[10005];
long long ans;
void dfs(int k){
    int minn=1e9+1,net;
    for(int i=0;i<a[k].size();i++){
        if(!mp[i]){
            if(a[k][i].second<minn){
                minn=a[k][i].second;
                net=a[k][i].first;
            }
        }
    }
    mp[k]=1;
    ans+=minn;
    dfs(net);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
    dfs(1);
}
