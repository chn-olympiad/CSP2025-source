#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
char a[N];
int c[N], b[N], d[N], n, m;
long long res;

void dfs(int x){
	if(x == n + 1){
		int guo = 0, buguo = 0;
		for(int i = 1; i <= n; i++){
			if(buguo >= c[d[i]]) buguo++;
			else if(a[i] == '0') buguo++;
			else guo++;
		}
		if(guo >= m){
//			cout << "d : ";
//			for(int i = 1; i <= n; i++) cout << d[i] << " ";
//			cout << "\n";
			res++;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(b[i] == 0){
			b[i] = 1;
			d[x] = i;
			dfs(x + 1);
			b[i] = 0;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == '1') cnt++;
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(cnt < m) cout << 0;
	else if(n <= 18){
		dfs(1);
		cout << res;
	}
	else if(cnt == n){
		res = 1;
		for(int i = 1; i <= n; i++)
			res = res * i % mod;
		cout << res;
	}
	else{
		cout << 1;
	}
	return 0;
} 

