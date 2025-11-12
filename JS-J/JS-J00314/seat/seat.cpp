#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,v,c,r;
	cin>>n>>m;
	int a[10000];
	cin>>a[0];
	v=a[0];
	for(int i=1;i<m*n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m*n;i++)
	{
		for(int j=i+1;j<m*n;j++)
		{
			if(a[i]<a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=0;i<m*n;i++)
	{
		if(a[i]==v)
		{
			c=(i+1)%n?(i+1)/n+1:(i+1)/n;
			if(c%2)
				r=(i+1)%n?(i+1)%n:n;
			else
				r=(i+1)%n?n-(i+1)%n:1;
			cout<<c<<" "<<r<<endl;
			break;
		}
	}
	return 0;
}
