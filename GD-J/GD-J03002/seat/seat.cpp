#include <bits/stdc++.h>
//
using namespace std ;
const int N=104 ;
int n,m,a[N*N],s,l,r ;
int main () {
	freopen ("seat.in","r",stdin) ;
	freopen ("seat.out","w",stdout) ;
//	freopen ("hh","w",stdout) ;
	cin>>n>>m ;
	cin>>a[1] ;
	s=1;
	for (int i=2;i<=n*m;i++) {
		cin>>a[i];
		if (a[i]>a[1])s++;
	}
//	cout<<s;
	if (s%n==0)l=s/n,r=n;
	else l=s/n+1,r=s%n;
	if (l%2==0) r=n-r+1;
	cout<<l<<" "<<r; 
	return 0 ;
}
