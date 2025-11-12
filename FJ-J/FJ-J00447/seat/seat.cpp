#include<bits/stdc++.h>
using namespace std;
int n,m,s,x;
int r,c;
int a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--) {
		if (a[i]==s) {
			x=n*m-i+1;
			break;
		} 
	}
	r=x/n;
	if (x%n==0) {
		if (r%2==0) c=1;
		else c=n;
	} else {
		if (r%2==1) c=n-(x-r*n)+1;
		else c=x-r*n;
		r++;
	}
	cout<<r<<" "<<c<<endl;
	return 0;
} 
