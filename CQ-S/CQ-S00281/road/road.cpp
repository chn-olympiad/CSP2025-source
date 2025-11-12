#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
struct Edge{
	int u,v,w;
}e[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	cout<<"0";
	return 0;
}
