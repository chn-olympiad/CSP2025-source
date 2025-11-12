#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

pair<pair<string, string>, int> delSame(pair<string, string> p) {
	int i = 0, j = 1;
	while (p.first[i] == p.second[i] && i <= min(p.first.size(), p.second.size())) {
		i++;
	} while (p.first[p.first.size() - j] == p.second[p.first.size() - j] && i + j < min(p.first.size(), p.second.size())) {
		j++;
	}
	pair<string, string> ans = { "", "" };
	for (int k = i; k <= p.first.size() - j; k++) {
		ans.first.push_back(p.first[k]);
	} for (int k = i; k <= p.second.size() - j; k++) {
		ans.second.push_back(p.second[k]);
	}
	pair<pair<string, string>, int> ans2 = { ans, i };
	return ans2;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	map<pair<string, string>, vector<pair<pair<string, string>, int> > > m;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		pair<pair<string, string>, int> p = delSame({ s1, s2 });
		try {
			m[p.first].push_back({ { s1, s2 }, p.second });
		} catch (string e) {
			m[p.first] = {{ { s1, s2 }, p.second }};
		}
	}
	while (q--) {
		int count = 0;
		string s1, s2;
		cin >> s1 >> s2;
		pair<pair<string, string>, int> p = delSame({ s1, s2 });
		vector<pair<pair<string, string>, int> > v = m[p.first];
		for (int i = 0; i < v.size(); i++) {
			int delta = p.second - v[i].second;
			if (delta < 0 || v[i].first.first.size() + delta > s1.size()) {
				continue;
			}
			bool flag = true;
			for (int j = 0; j < v[i].first.first.size(); j++) {
				if (v[i].first.first[j] != s1[j + delta]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				count++;
			}
		}
		cout << count << endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
