#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
int n, q;
string s[200005][3], t1, t2;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	_for(i, 1, n) cin >> s[i][1] >> s[i][2];
	_for(i, 1, q){
		int ans = 0;
		cin >> t1 >> t2;
		_for(i, 1, n){
			int a = t1.find(s[i][1]), b = t2.find(s[i][2]);
			if(a != string::npos && b != string::npos &&
				a == b &&
				t1.substr(0, a) == t2.substr(0, b) &&
				t1.substr(a + s[i][1].size(), t1.size() - a - s[i][1].size()) == t2.substr(b + s[i][2].size(), t2.size() - b - s[i][1].size())) ans++;
//			cout << t1.substr(0, a) << ' ' << t2.substr(0, b) << '\n';
//			cout << t1.substr(a + s[i][1].size(), t1.size() - a - s[i][1].size()) << ' ' << t2.substr(b + s[i][2].size(), t2.size() - b - s[i][1].size()) << '\n';
//			cout << ans << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}