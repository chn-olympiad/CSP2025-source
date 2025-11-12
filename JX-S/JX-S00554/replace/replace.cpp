#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, q;
unordered_map<string, string> mp;
unordered_map<string, int> num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
		string tmp;
		tmp += s1;
		tmp += s2;
		num[tmp]++;
	}
	for (int i = 1; i <= q; i++) {
		string q1, q2;
		cin >> q1 >> q2;
		string tmp;
		tmp += q1;
		tmp += q2;
		if (mp[q1] == q2) {
			cout << num[tmp] << '\n';
		}
	}
	return 0;
}
