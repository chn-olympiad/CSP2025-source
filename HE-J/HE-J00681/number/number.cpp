#include <bits/stdc++.h>
using namespace std;
long long num[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n = 0;
	cin>>s; 
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[n] = s[i] - 48;
			n += 1; 
		}
	}
	sort(num, num + n);
	for (int i = n - 1; i >=0; i--) {
		cout << num[i];
	}
	return 0;
} 
