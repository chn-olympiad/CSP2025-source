#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	int n = s.size();
	int a[n], j = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] < 'a' || s[i] > 'z') {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a, a + j);
	for (int i = j - 1; i >= 0; i--) {
		cout<<a[i];
	}
	return 0;
}
