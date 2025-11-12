#include<bits/stdc++.h>
using namespace std;
int a[101],b,c,d,e,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	c=n*m-(lower_bound(a+1,a+n*m+1,b)-a)+1;
	d=(c+n-1)/n;e=c%n;if(e==0)e=n;
	if(d&1)cout<<d<<" "<<e;
	else cout<<d<<" "<<n-e+1;
	return 0;
}
