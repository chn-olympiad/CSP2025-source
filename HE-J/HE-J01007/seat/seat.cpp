#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","d",stdout);
	int n,m;
	int a[100000];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	 } 
	int b=a[1];
	int f=0;
	int h=n*m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]<a[j+1])
			{
				int t=a[j];
				a[j]=a[j-1];
				a[j+1]=t; 
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			break;
		}
		f++;
	 }
	 int c,r;
	 cout<<f;
	int d=f/n;
	int e=f%n;
	cout<<e;
	if(d%2!=0)
	{
		c=d+1;
		r=m-e+1;
	 } 
	else
	{
		c=d+1;
		r=e;
	}
	cout<<c<<" "<<r;
}
