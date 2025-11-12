#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int num[N];
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int len=a.size(), cnt=0;
	for(int i=0; i<len; i++) {
		if(a[i] >= '0' && a[i] <= '9') {
			num[++cnt] = a[i]-'0';
		}
	}
	sort (num+1,num+1+cnt);
	if(a[1] == 0) {
		cout << 0;
		return 0;
	}
	for(int i=cnt; i>=1; i--) {
		cout << num[i];
	}
	return 0;
} 
