#include <bits/stdc++.h>
#define N 505

using namespace std;

int n, m, c[N], sum;
string s;

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
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = rd(); m = rd();
	cin >> s;
	for(int i = 1; i <= n; i++) c[i] = rd();
	for(int i = 0; i < s.size(); i++)
	if(s[i] == '1') sum ++;
	printf("%d", min(sum, m) );
	return 0;
}
//[0, 5] ·Ö  
