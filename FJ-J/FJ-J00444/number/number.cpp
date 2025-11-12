#include<bits/stdc++.h>
using namespace std;
int N[1000000 + 10];
bool cmp (int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int k = 0, l = s.length();
	for(int i = 0; i < l; ++ i) {
		if(s[i] >= '0' && s[i] <= '9') {
			N[k ++] = s[i] - '0';
		}
	}
	sort(N, N + k, cmp);
	for(int i = 0; i < k; ++ i) {
		printf("%d", N[i]);
	}
	return 0;
}
