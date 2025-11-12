#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[200];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	int g=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int p=0;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==g) p=i;
	}
//	cout<<p<<endl;
	int k=p;
	p%=n;
	if(p==0) {
		c=k/n;
		if(c%2==0) r=1;
		else r=n;
	} else {
		c=k/n+1;
		if(c%2==0) r=n-p+1;
		else r=p;
	}
	cout<<c<<" "<<r;
	return 0;
}
