#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
string s;
vector<int> m;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.length(); i++)
		if(s[i] >= '0' && s[i] <= '9')
			m.push_back(s[i] - '0');
	sort(m.begin(), m.end(), cmp);
	for(auto i : m)
		cout << i;
	return 0;
}