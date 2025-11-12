#include <bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
vector<node> G[10010];
int main(){
	freopen("road.in","s",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
    }
    for(int i=1;i<=m;i++){
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    cout<<0;
    return 0;
}
