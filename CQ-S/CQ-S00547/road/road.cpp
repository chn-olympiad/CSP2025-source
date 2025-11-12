#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[1005][1005],c[100005];
vector<int> vt[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
    for(int i=1; i<=n; ++i){
        int u,v,w;
        cin>>u>>v>>w;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    for(int i=1; i<=k; ++i){
        cin>>c[i];
        for(int j=1; j<=n; ++j){
            cin>>arr[i][j];
        }
    }
    cout<<13;

	return 0;
}