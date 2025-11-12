#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[10];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	int n = s.size();
	s = "#" + s;
	for (int i = 1; i <= n; i++)
		if ('0' <= s[i] && s[i] <= '9')
			a[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++)
			cout << i;
	return 0;
}
