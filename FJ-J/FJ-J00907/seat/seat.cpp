#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,s=0,t,c,r;
	cin>>n>>m;
	cin>>a;
	for(int i=1; i<n*m; i++) {
		cin>>t;
		if(t>a) {
			s++;
		}
	}
	c=s/n+1;
	r=s%n+1;
	if(c%2==0) {
		r=n-r+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
