#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1020],x,i,j,o,p,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	o=lower_bound(a+1,a+1+n*m,x)-a;
	o=n*m-o+1;
	p=o/n;
	h=o%(n*2);
	if(h==0)cout<<p<<" "<<1;
	else if(h<=n)
	{
		if(p%2==0)cout<<p+1<<" "<<h;
		else cout<<p<<" "<<h;
	}
	else cout<<p+1<<" "<<n*2-h+1;
	return 0;
}