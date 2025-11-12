#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, a,b,c, ans=0;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		ans+=c;
	}
	cout << ans;
	return 0;
	
}
