#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        int minn=1e9+7;
        int minp=0;
        for(pair<int,int> j:v[i]){
            if(j.first<minn){
                minn=j.first;
                minp=j.second;
            }
        }
        ans+=minn;
        for(int j=0;j<v[minp].size();j++){
            if(v[minp][j].first==minn&&v[minp][j].second==i){
                v[minp].erase(v[minp].begin()+j);
                break;
            }
        }
    }
    cout<<ans<<endl;
}
