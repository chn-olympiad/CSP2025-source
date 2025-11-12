#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long k;
long long u[100010];
long long v[100010];
long long w[100010];
long long x[1010][1010];
long long y;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	cin>>m;
	cin>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i];
		cin>>v[i];
		cin>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>y;
		for(int j=1;j<=n;j++){
			cin>>x[y][j];
		}
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n-1;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
