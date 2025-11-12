#include <iostream>
#include <vector>
#include <cstring>
#define endl "\n"
#define str string
#define ll long long
using namespace std;
vector<pair<str, str>> s;
vector<int> sd;
ll cnt;
void dfs(str st, str et) {
	if(st == et) {
		cnt++;
		return ;
	}
	int dd = -1;
	for(auto i : s) {
		dd++;
		for(int j = 0; j < st.length(); j++) {
			if(st[j] == i.first[j] && !sd[dd]) {
				bool cmp = 1;
				for(int l = j + 1; l < i.first.length(); l++)
					if(st[l] != i.first[l]) {
						cmp = 0;
						break;
					}
				if(cmp) {
					sd[dd] = 1;
					// cout << st.substr(0, (j - 1) < 0 ? 0 : j - 1) << " " << i.first << " " << i.second << " " << st.substr(j + i.second.length() - 1 > st.length() ? st.length() : j + i.second.length() - 1, -1) << endl;
					dfs(st.substr(0, (j - 1) < 0 ? 0 : j - 1) + i.second + st.substr(j + i.second.length() - 1 > st.length() ? st.length() : j + i.second.length() - 1, -1), et);
					sd[dd] = 0;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace3.in", "r", stdin);
	// freopen("replace.out", "w", stdout);
	ll n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		pair<str, str> input;
		cin >> input.first >> input.second;
		s.push_back(input);
		sd.push_back(0);
	}
	while(q--) {
		str a, b;
		cin >> a >> b;
		dfs(a, b);
		cout << cnt << endl;
	}
	return 0;
}