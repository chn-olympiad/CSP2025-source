#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int Mod = 998244353;
char c[N];
int a[N];
int n, m;

int main() {
	
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int cnt = 0;
	sort(a + 1, a + n + 1);
	do {
		for(int i = 1; i <= n; i++) cout << a[i] << ' ';
		int peo = 0;
		int lost = 0;
		for(int i = 1; i <= n; i++) {
			if(c[i] == '0') lost += 1;
			else if(a[i] > lost) {
				peo += 1;
			} else if(a[i] <= lost){
				lost += 1;
			}
		}
		cout << peo << '\n';
		if(peo >= m) cnt = (cnt + 1) % Mod;
	} while(next_permutation(a + 1, a + n + 1));
	
	cout << cnt;
	
	return 0;
}
