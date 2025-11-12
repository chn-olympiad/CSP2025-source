#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>w(n+1,0);
    vector<vector<int> >R(n+1,vector<int>(n+1,0));
    vector<vector<int> >C(k+1,vector<int>(n+1,0));
    int ans=0;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>w[i];
        ans+=w[i];
    }
    cout<<ans;
    return 0;
}

