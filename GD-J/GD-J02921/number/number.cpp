#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int a[N];
int idx = 0;
string s;

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++) {
		if(s[i] >= '0' && s[i] <= '9') a[++idx] = s[i] - '0';
	}
	
	sort(a + 1, a + idx + 1, greater<int>() );
	for(int i = 1; i <= idx; i++) cout << a[i];
	
	return 0;
} 
