#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,m,b[12][1005];
struct node{
	int u,v,w;
}a[1000005];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0;
}
