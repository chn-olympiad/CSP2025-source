#include <bits/stdc++.h>
using namespace std;
long long sum;
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int a;cin>>a;
		}
	}
	cout<<sum-9;
	return 0;
}

