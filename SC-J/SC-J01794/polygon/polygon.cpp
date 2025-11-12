#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[3]) {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}