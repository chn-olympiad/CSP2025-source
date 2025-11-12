#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
string s1[N], s2[N];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while(m--){
		string x, y;
		cin >> x >> y;
		int f = 0, b = 0;
		for(int i = 0; i < x.size(); i++)
			if(x[i] != y[i]){
				f = i;
				break;
			}
		for(int i = x.size() - 1; i >= 0; i--)
			if(x[i] != y[i]){
				b = i;
				break;
			}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int p1 = x.find(s1[i]), p2 = y.find(s2[i]);
			if(p1 > -1 && p2 > -1 && p1 == p2 && p1 <= f && p1 + s1[i].size() - 1 >= b) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
//30+pts
