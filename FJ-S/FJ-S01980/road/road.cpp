#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000001],v[1000001];
long long w[1000001];
struct country{
	long long c,a[1000001];
}build[11];
long long ans; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
		ans+=w[i];
	}for(int i=1;i<=k;i++){
		cin >> build[i].c;
		for(int j=1;j<=n;j++){
			cin >> build[i].a[j];
		}
	}
	cout << ans;
} 
