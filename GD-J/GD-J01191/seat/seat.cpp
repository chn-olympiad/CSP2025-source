#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,mod,p,a1,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	p=n*m-(lower_bound(a+1,a+n*m+1,a1)-a)+1;
	mod=(p%n?p%n:n);
	c=ceil(1.0*p/n);
	cout<<c<<' '<<(c&1?mod:n-mod+1);
}
