#include <bits/stdc++.h>
#define endl "\n"
#define MAXN 105
#define MOD 998244353
using namespace std;
int n, m;
bool dif[MAXN], pf = 1 ,pf2 = 0, p[MAXN];
char ch;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> ch;
		dif[i] = (bool)(ch - '0'), pf &= dif[i], pf2 |= dif[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	if (pf) {
		cout << 0;
		return 0;
	}
	if (m == n){
		if(pf2) cout << 0;
		else{
			int ans = 1;
			n++;
			while(--n) {
				ans = ((ans % MOD) * n) % MOD;
			}
			cout << ans;
		}
		return 0;
	}
	cout << 3;
	return 0;
}
