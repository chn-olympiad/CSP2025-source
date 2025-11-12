#include <iostream>
#include <algorithm>
using namespace std;

const int MXN = 505;
int n, m, c[MXN], p[MXN], ans;
char s[MXN];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i += 1)
		cin >> s[i];
	for (int i = 1; i <= n; i += 1)
		cin >> c[i];
		
	for (int i = 1; i <= n; i += 1) p[i] = i;
	do{
		int sum = 0;
		for (int i = 1; i <= n; i += 1){
			if (sum >= c[p[i]] || s[i] == '0') sum += 1;
		}
		if (n - sum >= m) ans += 1;
	}
	while (next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}
