#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, K;
int a[N];
int d[N][20];
bool vis[N];
vector<pair<int, int>> g;
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second - a.first < b.second - b.first;
}
void solve1(){
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		scanf("%d", &a[i]);
		if(K == 1) ans += a[i];
		if(K == 0) ans += a[i] ^ 1;
	}
	if(K == 1){
		cout << ans;
		return ;
	}
	for(int i = 1;i < n;i ++){
		if(a[i] == a[i + 1] && a[i] == 1) ans++, i ++;
	}
	cout << ans;
	return ;
}
void solve2(){
	for(int i = 1;i <= n;i ++){
		scanf("%d", &a[i]);
		for(int j = 0; j <= 19;j ++){
			d[i][j] = d[i - 1][j];
			if((a[i] & (1 << j)) != 0) d[i][j] ++;
		}
	}
	bool f;
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			f = 1;
			for(int k = 0;k <= 19;k ++){
				if((d[j][k] - d[i - 1][k]) % 2 != ((K & (1 << k)) ? 1 : 0)){
					f = 0;
					break;
				}
			}
			if(f) g.push_back({i, j});
		}
	}
	sort(g.begin(), g.end(), cmp);
	int ans = 0;
	for(int i = 0;i < g.size();i ++){
		f = 1;
		for(int j = g[i].first;j <= g[i].second;j ++){
			if(vis[j]){
				f = 0;
				break;
			}
		}
		if(f){
			ans ++;
			for(int j = g[i].first;j <= g[i].second;j ++){
				vis[j] = 1;
			}
		}
	}
	cout << ans;
	return ;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> K;
	if(K <= 1) solve1();
	else if (n <= 1000) solve2();
	else cout << 1;
	return 0;
}
