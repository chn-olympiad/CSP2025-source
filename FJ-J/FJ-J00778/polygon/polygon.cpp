#include<bits/stdc++.h>
using namespace std;
long long n,a[10001];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==3) {
		for(int i=1; i<=n; i++) {
			if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2]) {
				cout<<1;
				break;
			} else {
				cout<<n+1;
				break;
			}
		}
	} else cout<<n;
	return 0;
}
