#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int t, n, a[N], b[N], c[N], d[N], f[N], cnta, cntb, cntc, ans, mx;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n; ans = cnta = cntb = cntc = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] >= max(b[i], c[i])) cnta++, f[i] = 1, ans += a[i];
			else if(b[i] >= max(a[i], c[i])) cntb++, f[i] = 2, ans += b[i];
			else cntc++, f[i] = 3, ans += c[i];
		}
//		for(int i = 1; i <= n; i++) cout << f[i] << ' ';
//		cout << '\n';
//		cout << cnta << ' ' << cntb << ' ' << cntc << '\n';
//		cout << ans << '\n';
		if(cnta > n/2){
			for(int i = 1; i <= n; i++){
				if(f[i] == 1) d[i] = max(b[i], c[i]) - a[i];
				else d[i] = -1e9;
			}
			sort(d + 1, d + n + 1);
			for(int i = n; i > n-cnta+n/2; i--) ans += d[i];
		}
		if(cntb > n/2){
			for(int i = 1; i <= n; i++){
				if(f[i] == 2) d[i] = max(a[i], c[i]) - b[i];
				else d[i] = -1e9;
			}
			sort(d + 1, d + n + 1);
			for(int i = n; i > n-cntb+n/2; i--) ans += d[i];
		}
		if(cntc > n/2){
			for(int i = 1; i <= n; i++){
				if(f[i] == 3) d[i] = max(a[i], b[i]) - c[i];
				else d[i] = -1e9;
			}
			sort(d + 1, d + n + 1);
			for(int i = n; i > n-cntc+n/2; i--) ans += d[i];
		}
		cout << ans << '\n';
	}
	return 0;
} 
