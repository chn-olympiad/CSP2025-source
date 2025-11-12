#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int num[N];
string s;
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int i;
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	int k = 0;
	for (i = 0; i < s.size(); ++i) {
		if (isdigit(s[i])) num[++k] = s[i] - '0';
	}
	
	sort(num + 1, num + 1 + k, cmp);
	
	for (i = 1; i <= k; ++i) printf("%d", num[i]); 
	
	return 0;
}

