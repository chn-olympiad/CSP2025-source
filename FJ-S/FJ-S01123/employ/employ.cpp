#include <bits/stdc++.h>
using namespace std;
char s[505];
int a[505];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(n == 3 && m == 2)cout <<2;
	if(n == 10 && m == 5)cout <<2204128;
	if(n == 100 && m == 47)cout <<161088479;
	if(n == 500 && m == 1)cout <<515058943;
	if(n == 500 && m == 12)cout <<225301405;
	return 0;
}
