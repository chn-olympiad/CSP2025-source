#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,s,m0,n0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	x=a[0];
	sort(a,a+n*m);
	s=lower_bound(a,a+n*m,x)-a;
	s=n*m-s-1;
	m0=s/n+1;
	n0=s-n*m0+n+1;
	if(m0%2==0) n0=n-n0+1;
	cout<<m0<<" "<<n0;
	return 0;
}
