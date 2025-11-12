#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,b;
	cin>>n>>m;
	b=n*m;
	int a[b],t,c;
	for(i=0;i<b;i++)
	{
		cin>>a[i];
	}
	t=a[0];
	for(i=0;i<=b;)
	{
		for(j=0;j<=b;j++)
		{
			if(a[j]<a[j+1])
			{
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;	
			}
		}
		b--;
	}
	b=0;
	for(i=0;i<n*m;i++)
	{
		if(a[i]<=100)
		{
			b++;
		}
		if(t==a[i])
		{
			break;
		}
	}
	c=b/n;
	if(n*c<b)
	{
		c++;
	}
	if(b%n==0)
	{
		t=n;
	}
	else
	{
		t=b%n;
	}
	if(c%2==0)
	{
		cout<<c<<" "<<n-t+1;
	}
	else
	{
		cout<<c<<" "<<t;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
