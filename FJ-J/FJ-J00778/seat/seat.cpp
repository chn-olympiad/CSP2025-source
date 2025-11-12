#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1001],a[101][101],c,r,x,y;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>s[i];
	}
	x=s[1];
	sort(s+1,s+(n*m)+1);
	for(int i=n*m,j=1;i>=1;i--,j++) {
		if(s[i]==x) y=j;
	}
	c=((y-1)/n)+1;
	if(c%2==1) {
		if(y%n) r=y%n;
		else r=n; 
	} 
	else {
		if(y%n) r=n+1-(y%n);
		else r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
