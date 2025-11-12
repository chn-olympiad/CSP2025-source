#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
string s;
int cnt[16]; 
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i) if (s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++; 
	for (int i = 9; i >= 0; --i) while (cnt[i]--) cout << i;
	return 0;
}

