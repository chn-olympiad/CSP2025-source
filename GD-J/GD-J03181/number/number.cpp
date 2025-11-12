#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
string s;
int a[MAXN];

bool cmp(int s1, int s2) {
	return s1 > s2;
}

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	
	int n = s.size();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		char si = s[i];
		
		if (si - '0' >= 0 && si - '0' <= 9) {
			a[++cnt] = si - '0';
		}
	}
	
	sort(a + 1, a + cnt + 1, cmp);
	
	for (int i = 1; i <= cnt; i++) {
		cout << a[i];
	}
	
	return 0;
} 
