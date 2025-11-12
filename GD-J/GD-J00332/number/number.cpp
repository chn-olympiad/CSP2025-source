#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vector<int>
#define sz(a) ((int)a.size())
using namespace std;

string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	map<int, int> a;
	L(i, 0, sz(s) - 1) {
		if(s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; i--) {
		for(int j = 1; j <= a[i]; j++)
			cout << i;
	}
	return 0;
}
