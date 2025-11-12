#include <bits/stdc++.h>
//六六六不会做 
using namespace std;
const long long N = 998244353;
int n, a[5005], f[5005];
vector<int> b, g[5005];
long long bs;
int sum(int s){
	int u = 0;
	for (int i = 1; i <= s; i++) u += b[i];
	return u;
}
int maxn(int s){
	int u = 0;
	for (int i = 1; i <= s; i++) u = max(u, b[i]);
	return 2 * u;
}
bool polygon(int s){
	if (sum(s) > maxn(s)) return true;
	return false;
}
void dfs(int step){
	int p = 1;
	if (step - 1)
		if (polygon(step - 1)){
			for (int j = 1; j <= bs; j++) if (g[j] == b) p = 0;
			if (p)
				bs++; bs %= N;
				for (int i = 1; i < step; i++) g[bs].push_back(b[i]);
				cout << '\n';
	}
	if (step > n) return;
	for (int i = 1; i <= n; i++){
		if (f[i]) continue;
		b.push_back(a[i]);
		f[i] = 1;
		dfs(step + 1);
		b.back();
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		fill(f + 1, f + n + 1, 0);
		dfs(i);
	}
	cout << bs;
	return 0;
	//0分代码(标准反面教材) 
}
