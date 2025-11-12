#include<bits/stdc++.h>
using namespace std;

#define Mod 998244353
long long n, a[5001], cho[5001], Ans;

void dfs(int cur, int lim){
	if(cur == lim){
		long long SumL = 0, MaxL = 0;
		for(int i = 1; i <= n; i++){
			if(cho[i] == 1){
				SumL += a[i];
				MaxL = max(MaxL, a[i]);
			}
		}
		if(SumL > MaxL * 2){
			Ans++;
			Ans %= Mod;
		}
		return ;
	}
	cur++;
	cho[cur] = 0;
	dfs(cur, lim);
	cho[cur] = 1;
	dfs(cur, lim);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	memset(cho, 0x3f, sizeof(cho));
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 3; i <= n; i++){
		dfs(0, i);
		Ans %= Mod;
	}
	cout << Ans << endl;
	return 0;
}

