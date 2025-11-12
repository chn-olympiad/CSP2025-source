#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
str s;
vector<ll> vec;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> s;
	for (const char & c : s)
		if (c >= '0' && c <= '9')
			vec.emplace_back(c ^ 48);
	sort(vec.begin(), vec.end(), greater<ll>());
	for (const ll & v : vec)
		cout << v;
	cout << '\n';
	return 0;
}