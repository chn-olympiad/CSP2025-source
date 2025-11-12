#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[200],r,c;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			c=ceil(i*1.0/n);
			cout<<c<<' ';
			if(c%2==1)cout<<i-n*(c-1);
			else cout<<n-(i-n*(c-1))+1;
			break;
		}
	}
	return 0;
}
