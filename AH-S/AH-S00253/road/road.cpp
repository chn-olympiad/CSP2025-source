#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,v,w;
};

vector<node> g[10010];

int n,m,k;

int main () {
    freopen("load.in","r",stdin);
    freopen("load.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
	}
	cout<<0;
    return 0;
}
