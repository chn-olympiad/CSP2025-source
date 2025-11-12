#include <bits/stdc++.h>
using namespace std;
vector<int> f;
int ans = 0, n, k;
int mxor(int s, int e){
	int res = f[s];
	for (int i = s + 1; i <= e; i++){
		res = res ^ f[i];
	}
	return res;
}
void dfs(int s){
	if (s > n - 1){
		return;
	} 
	ans++;
	int i;
	for (;s <= n; s++){
		for (i = s; i <= n; i++){
			if (mxor(s, i) == k){
				dfs(i + 1);
				return;
			}
		}
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int tem;
		cin >> tem;
		f.push_back(tem);
	}
	dfs(0);
	cout << ans;
	return 0;
} 
