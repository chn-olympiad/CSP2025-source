#include <bits/stdc++.h>
#define N 200001
using namespace std;

int n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	
	map<string, map<string, int>> mp;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int l = 0;
		for (int j = 0; j < s1.size(); j++)
			if (s1[j] == s2[j])
				l++;
			else
				break;
		int r = s1.size() - 1;
		for (int j = s1.size() - 1; j; j--)
			if (s1[j] == s2[j])
				r--;
			else
				break;
		string s;
		for (int j = l; j <= r; j++)
			s += s1[j];
		string t;
		for (int j = l; j <= r; j++)
			t += s2[j];
		mp[s][t]++;
	}

	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			printf("0\n");
			continue;
		}
		bool ok = false;
		for (int j = 0; j < t1.size() && !ok; j++) {
			if (t1[j] == t2[j]) {
				ok = true;
			}
		}
		if (ok) {
			int l = 0;
			for (int j = 0; j < t1.size(); j++)
				if (t1[j] == t2[j])
					l++;
				else
					break;
			int r = t1.size() - 1;
			for (int j = t1.size() - 1; j; j--)
				if (t1[j] == t2[j])
					r--;
				else
					break;
			string s;
			for (int j = l; j <= r; j++)
				s += t1[j];
			string t;
			for (int j = l; j <= r; j++)
				t += t2[j];
			if (mp.find(s) != mp.end()) {
				printf("%d\n", mp[s][t]);
			} else {
				puts("0");
			}
		} else {
			puts("0");
		}
	}
	return 0;
}