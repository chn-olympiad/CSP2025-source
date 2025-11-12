#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
using namespace std;

const int N=2e3+10;
int n, q, res, l, r, siz, ans;
string s1, s2, t1, t2;

int Find (string s) {
	for (int i=0; i < s.size (); i++) {
		if (s[i] == 'b') return i;
	}
	return 0;
}

struct node {
	string a, b;
};

bool operator < (node a, node b) {
	if (a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

map <node, int> mp;

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> q;
	for (int i=1; i <= n; i++) {
		cin >> s1 >> s2;
		mp[{s1,s2}]++, siz+=s1.size ();
	}
//	cout << "1";
	if (siz <= 2000) {
		for (int i=1; i <= q; i++) {
			cin >> s1 >> s2;
			res=0;
			if (s1.size () != s2.size () ) {
				cout << "0\n";
				continue;
			} l=N, r=0;
			for (int j=0; j < s1.size (); j++) {
				if (s1[j] != s2[j]) l=min (l, j), r=max (r, j);
			}
			for (int j=0; j < s1.size (); j++) {
				t1=t2="";
				for (int k=j; k < s1.size (); k++) {
					t1+=s1[k], t2+=s2[k];
					if (j <= l && k >= r) res+=mp[{t1,t2}];
				}
			}
			cout << res << '\n';
		}
	}
	else {
		while (q--) cout << "0\n";
	}
	return 0;
}

