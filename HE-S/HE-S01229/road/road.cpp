#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
struct node{
	int u, v, w;
}s[1000005];
int a[1000005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> s[i].u >> s[i].v >> s[i].w;
		ans += s[i].w;
	}
	while(k--){
		for(int i = 1; i <= n + 1; i++){
			cin >> a[i];
		}
	}
	cout << ans;
	return 0;
}
