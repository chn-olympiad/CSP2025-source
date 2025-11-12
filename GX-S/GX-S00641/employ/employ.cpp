#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6,mod = 998244353;
int a[N],n,m,c[N],ans;
char s[N];
bool used[N];
void check(){
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		if (c[a[i]] <= i - cnt - 1) continue;
		if (s[i] == '1'){
			++cnt;
		}
	}
	if (cnt >= m){
		++ans;
		ans %= mod;
	}
}

void dfs(int start){
	if (start == n + 1){
		check();
		return ;
	}
	for (int i = 1; i <= n; ++i){
		if (!used[i]){
			used[i] = 1;
			a[start] = i;
			dfs(start + 1);
			used[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> s[i];
	}
	for (int i = 1; i <= n; ++i){
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
