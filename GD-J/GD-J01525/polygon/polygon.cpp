#include<bits/stdc++.h>
using namespace std;
int a[10001000];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	int mx =max(a[1],max(a[2],a[3]));
	if(n<=3) {
		if((a[1] + a[2] + a[3]) < mx * 2) cout<<"0";
		else cout<<"1";
	} else {
		long long num = 0;
		for(int i=3; i<=n; i++) {
			num = (num + ((n*(n-1) % 998244353)*(n-2)) / 6) % 998244353;
		}
		cout<<num % 998244353;
	}
	return 0;
}

