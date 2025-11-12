#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, q;
string s[N][5], t[N][5];
int ans = 0;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1; i <= q; i++){
		ans = 0;
		cin >> t[i][1] >> t[i][2];
		for(int j = 1; j <= n; j++){
			for(int l = 1; l <= (int)t[i][1].size() - (int)s[j][1].size() + 1; l++){
				bool xd = true;
				string yl = t[i][1];
				for(int r = l, k = 1; r <= l + (int)s[j][1].size() - 1; r++, k++){
					if(s[j][1][k - 1] != t[i][1][r - 1]){
						xd = false;
						break;
					}
				}
				if(xd){
//					cout << j << ' ' << l << '\n';
//					cout << t[i][1] << '\n'; 
					for(int r = l, k = 1; r <= l + (int)s[j][1].size() - 1; r++, k++){
						t[i][1][r - 1] = s[j][2][k - 1];
					}
//					cout << t[i][1] << '\n';
					if(t[i][1] == t[i][2]){
						ans++;
//						cout << t[i][1] << ' ' << t[i][2] << '\n';
					}
				}
				t[i][1] = yl;
			} 
		}
		cout << ans << '\n'; 
	}
	return 0;
}
//18 : 00 25pts
