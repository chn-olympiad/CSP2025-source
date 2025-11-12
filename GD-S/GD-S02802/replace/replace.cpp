#include <bits/stdc++.h>
#define N 200005

using namespace std;

int n, q, ans;

map<string, map<string, int> > mp;

int rd() {
	int S = 0, F = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') F = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		S = (S << 3) + (S << 1) + (ch ^ 48);
		ch = getchar();
	}
	return S * F;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = rd(); q = rd();
	for(int i = 1; i <= n; i++) {
		string A, B;
		cin >> A >> B;
		mp[A][B] ++;
	}
	if(q > 100) {
		while(q --) puts("0");
		return 0;
	}
	while(q --) {
		string s, t, A, B;
		ans = 0;
		cin >> s >> t;
		int a = 0, b = s.size() - 1;
		while(s[a] == t[a]) a ++;
		while(s[b] == t[b]) b --;
		for(int i = 0; i <= a; i++)
		for(int j = b; j < s.size(); j++) {
			A = B = "";
			for(int k = i; k <= j; k++) A += s[k], B += t[k];
			ans += mp[A][B];
//			cout <<":"<< A << " " << B << "\n";
		}
		printf("%d\n", ans);
	}
	return 0;
}
//[0, 8] ·Ö 
