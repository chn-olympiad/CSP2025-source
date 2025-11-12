#include<bits/stdc++.h>
using namespace std;
int a[505];
int b[505];
int c[505];
int ans;
int n, m;
string t;
void dfs(int s){
	if (s > n){
		int cnt = 0;
		int f = 0;
		for (int i = 1; i <= n; i++){
			if (cnt < b[i]){
				if (t[i - 1] == '1'){
					f++;
				}
				else{
					cnt++;
				}
			}
			else{
				cnt++;
			}
		}
		if (f >= m)ans++;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (c[i] == 0){
			c[i] = 1;
			b[s] = a[i];
			dfs(s + 1);
			c[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> t;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
} 
