//GZ-S00290 贵阳市白云区华师一学校
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, l, r) for (int i = l; i >= r; i--)
using namespace std;

const int N = 2e5 + 5;

int n, q;
map<string, string> s;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	upp(i, 1, n) {
		string s1, s2;
		cin >> s1 >> s2;
		s[s1] = s2;
	}
	while(q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		int l, r;
		upp(i, 0, len - 1) if (s1[i] != s2[i]) {
			l = i;
			break;
		}
		dww(i, len - 1, 0) if (s1[i] != s2[i]) {
			r = i;
			break;
		}
		int res = 0;
		upp(i, 0, l) {
			string t1 = "", t2 = "";
			upp(j, i, len - 1) {
				t1 = t1 + s1[j];
				t2 = t2 + s2[j];
				if (j >= r && s[t1] == t2) res++;
			}
		}
		cout << res << endl; 
	}
	
	return 0;
}
