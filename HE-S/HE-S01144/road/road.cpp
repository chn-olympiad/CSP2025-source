#include <bits/stdc++.h>
using namespace std;
const int _ = 10086, __ = 1400000;
int zong, tot, father[_], n, m, k, c[22], a[22][_];
bool f;
long long ans;
struct hhh{
	int x, y, z;
}r[__];
inline bool bbb(hhh a, hhh b){
	return a. z < b. z;
}
inline int find(int x){
	return (father[x] == x) ? x : father[x] = find(father[x]);
}
inline void kruskal(){
	for(int i = 1; i <= n + k; i ++){
		father[i] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= zong; i ++){
		if(find(r[i]. x) != find(r[i]. y)){
			ans += r[i]. z;
			cnt ++;
			father[find(r[i]. x)] = find(r[i]. y);
		}
		if(cnt == n + k - 1){
			return ;
		}
	}
	return ;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		cin >> r[i]. x >> r[i]. y >> r[i]. z;
	}
	zong = m;
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		if(c[i]){
			f = 1;
		}
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
		}
	}
	if(! f){
		for(int i = 1; i <= k; i ++){
			for(int j = 1; j <= n; j ++){
				++ zong;
				r[zong]. x = i + n, r[zong]. y = j, r[zong]. z = a[i][j];
			}
		}
		sort(r + 1, r + zong + 1, bbb);
		kruskal();
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= k; i ++){
			for(int j = 1; j <= n; j ++){
				++ zong;
				r[zong]. x = i + n, r[zong]. y = j, r[zong]. z = a[i][j];
			}
		}
		sort(r + 1, r + zong + 1, bbb);
		kruskal();
		cout << ans;
	return 0;
}
