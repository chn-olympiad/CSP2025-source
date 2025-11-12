#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 25;

int n, q;

string a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for(string x, y; q--;) {
		cin >> x >> y;
		int xlen = x.size(), ylen = y.size(), ans = 0;
		if(xlen != ylen){
			cout << "0\n";
			continue;
		}
		for(int i = 0; i < xlen; i++) {
			for(int j = 1; j <= n; j++) {
				if(x.substr(i, a[j].size()) == a[j]) {
					ans += (x.substr(0, i) + b[j] + x.substr(i + b[j].size()) == y);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
