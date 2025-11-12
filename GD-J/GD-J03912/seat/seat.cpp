#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],xm,xm1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		xm=a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xm)
		xm=i;
	}
	xm=n*m-xm+1;
	xm1=xm;
	if(xm%n==0)
	{
		if((xm/n)%2==0)
		cout<<xm/n<<" "<<1;
		else
		cout<<xm/n<<" "<<n; 
	}
	else
	{
		xm-=(xm/n)*n;
		if((xm1/n+1)%2==0)
			cout<<xm1/n+1<<" "<<n-xm+1;
		else
			cout<<xm1/n+1<<" "<<xm;
	}
	return 0;
}
