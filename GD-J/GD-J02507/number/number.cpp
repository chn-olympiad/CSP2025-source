#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
vector<ll> ans;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (auto i : s) if (isdigit(i)) ans.push_back(i - '0');
	sort(ans.begin(), ans.end(), greater<int>());
	for (auto i : ans) cout << i;
	return 0;
}

/*
08:44, AC All 4 test cases
#Shang4Shan3Ruo6Shui4e
Intel Core Ultra 9 285K?传奇少爷机？ orz CCF is so rich!
So, when can CCF use IOI 赛制?
Ultra 9 285K 性能核都出来了，when can release NOI Linux 2.1?
*/

/*
11:38, everything is ok
3rd CSP-J(but haven't got any prizes yet), Give me a 1= pls
*/
