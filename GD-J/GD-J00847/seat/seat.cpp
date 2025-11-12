#include <bits/stdc++.h>
using namespace std;
int n, m, i, p, r, c, a[207];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		p+=(a[i]>=a[1]);
	}
	c=(p-1)/n+1;
	r=p%n+n*(p%n==0);
	if(c%2==0)r=n+1-r;
	cout<<c<<" "<<r<<"\n";
	return 0;
}

