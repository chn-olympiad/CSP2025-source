#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;
int n, k, ans, a[maxn], s[maxn][maxn];
bool vis[maxn];
bool all_1 = true, all_01 = true;

void solve1(){
	if(k == 0) cout << n / 2;
	else cout << n;
	return;
}

void solve01(){
	if(k == 1){
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i] == 1) ans++;
		}
		cout << ans;
		return;
	}
	else{
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i] == 0) ans++;
			else if(a[i] == 1 && a[i + 1] == 1) ans++;
		}
		cout << ans;
		return;
	}
}

int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] != 1) all_1 = false;
		if(a[i] >= 2) all_01 = false;
	}
	if(all_1){
		solve1();
		return 0;
	}
	if(all_01){
		solve01();
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			s[i][j] = s[i][j - 1] ^ a[j];
			if(s[i][j] == k && !vis[i] && !vis[j]){
				ans++;
				for(int k = i; k <= j; ++k) vis[k] = true;
			} 
		}
	}
	cout << ans;
	return 0;
}