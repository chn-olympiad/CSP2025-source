#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],w[500][500],g,h,l;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s==a[i]) g=i;
	}
	if(g<=n) h=g,l=1;
	else
	{
		if(g%n==0) l=g/n;
		else l=g/n+1;
		if(l%2==0) h=n-g%n+1;
		else h=g%n;
	}
	cout<<l<<" "<<h;
	return 0;
}
