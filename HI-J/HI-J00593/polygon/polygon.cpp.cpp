#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005],big=0,all=0;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	if(n<3) {
		cout << "0";
		return 0;
	}
	cout << n;
	return 0;
} 
