#include <bits/stdc++.h>
using namespace std;

int u[1000000],v[1000000],w[1000000];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,hao,xu,ans;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	hao=(1+(n-1))*(n-1)/2-m;
	xu=n-1-hao;
	sort(w+1,w+n+1);
	for(int i=1;i<=xu;i++){
		ans+=w[i];
	}
	cout << ans;
	return 0;
}
