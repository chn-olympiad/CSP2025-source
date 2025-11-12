#include <iostream>

using namespace std;

const int MOD = 998244353, N = 505;

int n, m, c[N], ans, use[N], arr[N];
string s;

void dfs(int pos){
	if(pos == n){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(cnt >= c[arr[i]] || s[i] == '0') cnt++;
		}
		if(n - cnt >= m) ans++;
		return;
	}
	for(int i = 0; i < n; i++){
		if(!use[i]){
			arr[pos] = i;
			use[i] = 1;
			dfs(pos + 1);
			use[i] = 0;
		} 
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	dfs(0);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}