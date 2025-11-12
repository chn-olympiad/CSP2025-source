#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d,c=1,b=1;
	d=n*m;
	cin>>n>>m;
	int a[d];
	for(int i=0;i<=d;i++)
	{	
		cin>>a[i];
	}
	for(int i=0;i<=d;i++)
	{
		if(b>1)
		 for(int j=0;j<=n;j++)
			b=b+1;
			c=c+1;
	}
	cout<<c<<' '<<b;
	return 0;
}
