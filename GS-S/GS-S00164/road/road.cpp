#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;
int u[1005000],v[1005000],w[1005000],a[1005000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int minn=1e9+10;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	for(int i=1;i<=k+1;i++){
		cin>>a[i];
	}
	sort(w+1,w+m+1);
	cout<<w[1]+w[2];
	return 0;
}
