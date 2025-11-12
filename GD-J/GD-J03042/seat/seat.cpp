#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int num=a[1];
	for(int i=2;i<=n*m;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,greater<int>());
	int pos=0;
	for(int i=1;i<=n*m;i++) {
		if(a[i]==num) {
			pos=i;
			break;
		}
	}
	int c=(pos+n-1)/n;
	cout<<c<<' ';
	if(c%2==1) {
		if(pos%n==0) {
			cout<<n;
		}
		else {
			cout<<pos%n;
		}
	}
	else {
		if(pos%n==0) {
			cout<<1;
		}
		else {
			cout<<n-pos%n+1;
		}
	}
	return 0;
}
