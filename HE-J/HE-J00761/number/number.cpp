#include <bits/stdc++.h>
using namespace std;
	int sm[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[1000005];

	long long n = 0;
	
	for (int i = 0;i < s;i++) {
		cin >> s[i];
		n++;
	}
		
	for (int i = 0;i < n;i++) {
		if (s[i] >= '0'&& s[i] <= '9') {
			sm = s[i];
		}
	}
	n = sm.size();
	sort(sm,sm + n);
	for (int i = 0;i < n;i++) {
		cout << sm[i];
	}
	return 0;
} 
