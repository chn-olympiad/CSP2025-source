#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],f,p,l,h;
bool sum(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	f=a[1];
	for(int i=2;i<=n*m;i++)	cin>>a[i];
	sort(a+1,a+1+n*m,sum);
	for(int i=1;i<=n*m;i++)
		if(a[i]==f)
		{
			p=i;
			break;
		}
	if(p%n==0)	l=p/n;
	else	l=p/n+1;
	cout<<l<<" ";
	if(l%2==1)
	{
		if(p%n==0)	h=n;
		else	h=p%n;
	}
	else
	{
		if(p%n==0)	h=1;
		else	h=m+1-(p%n);
	}
	cout<<h;
	return 0;
}