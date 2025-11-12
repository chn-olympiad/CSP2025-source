#include<bits/stdc++.h>
using namespace std;
const int MOD = 998'244'353;
vector<int> v;
int n, cnt, ls[5005];
void dfs(int k){
	if (k >= n){
		int sum = 0, maxn = 0;
		for (auto i : v){
			sum += i;
			maxn = max(i, maxn);
		}
		if (sum > maxn * 2) cnt ++;
		cnt %= MOD;
		return;
	}
	dfs(k + 1);
	v.push_back(ls [ k ]);
	dfs(k + 1);
}
int main(){
	cin >> n;
	for (int i = 1;i <= n; ++ i) cin >> ls [ i ];
	dfs(1);
	cout << cnt % MOD;
	return 0;
}

