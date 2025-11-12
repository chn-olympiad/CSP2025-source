#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int n, q, cnt;
string s, t;
map<string, vector<string>> combination;

void dfs(int process1, int process2, int index) {
	if (process1 != -1 && process2 != -1) {
		string sub_string;
		for (int i = process1; i < process2; ++i)sub_string += s[i];
		if (combination.find(sub_string) == combination.end())return;
		string now;
		for (int i = 0; i < process1; ++i)now += s[i];
		for (string e: combination[sub_string]) {
			now += e;
			for (int i = process2; i < s.size(); ++i)now += s[i];
			if (now == t) {
				++cnt;
				return;
			}
		}
	}
	for (int i = index + 1; i < s.size(); ++i) {
		if (process1 != -1) {
			dfs(i, process2, i);
		} else {
			dfs(process1, i, i);
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		if (combination.find(s) != combination.end()) {
			combination[s].push_back(t);
		} else {
			vector<string> tmp;
			tmp.push_back(t);
			combination[s]= tmp;
		}
	}
	while (q--) {
		cnt = 0;
		cin >> s >> t;
		dfs(-1, -1, -1);
		cout << cnt << endl;
	}
	return 0;
}
