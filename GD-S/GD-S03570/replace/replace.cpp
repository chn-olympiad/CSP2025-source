//0pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s[N][2];

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Med) - (&Mst)) / 1024.0 / 1024 << "MB\n";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> s[i][0] >> s[i][1];
	while(q--){
		string t[2];
		cin >> t[0] >> t[1];
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			int now = t[0].find(s[i][0]);
			if(now != -1){
				string x = t[0].substr(0, now) + s[i][1] + t[0].substr(now + s[i][0].size());
//				cerr << x << '\n';
				ans += (x == t[1]);
			}
		}
//		cerr << '\n';
		cout << ans << '\n';
	}
	
	return 0;
}
