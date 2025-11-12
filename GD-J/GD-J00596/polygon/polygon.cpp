#include<bits/stdc++.h>
using namespace std;
long long n,a[5090];
bool check_1() {
	for(int i=0; i<n; i++) {
		if(a[i]!=1)return false;
	}
	return true;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++)cin>>a[i];
	if(n==3) {
		int s=a[0]+a[1]+a[2],ma=max({a[0],a[1],a[2]});
		if(s>(ma*2)) {
			cout<<1;
			return 0;
		} else {
			cout<<0;
			return 0;
		}
	}
	if(check_1()) {
		cout<<(((n-3)+1)*(n-3))/2;
		return 0;
	}
	return 0;
}
