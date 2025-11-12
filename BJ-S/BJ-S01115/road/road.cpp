#include<bits/stdc++.h>
using namespace std;
struct node{
    int s,x;
};
//vector<node>a[10010];
int f[10010];
map<int,map<int ,int>>mp;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>v>>w>>u;
        mp[w][v]=max(mp[w][v],u);
        mp[v][w]=max(mp[v][w],u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i])continue;
        long long ma=1e18,mx=0;
        for(auto s:mp[i]){
            if(s.second<ma){
                ma=s.second;
                mx=s.first;
            }
            if(s.second==ma&&f[s.first]==0){
                mx=s.first;
            }
        }
        cnt+=ma;
        f[i]=1;
        f[mx]=1;
        cout<<i<<" "<<mx<<"\n";
    }
    cout<<cnt;
    return 0;
}

