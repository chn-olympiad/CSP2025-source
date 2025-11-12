#include<bits/stdc++.h>
using namespace std;
int x,y;
int a[105];
int z;
int m;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++)
	{
		cin>>a[i];
	}
	m=a[1];
	for(int k=1;k<=x*y;k++){
		for(int i=1;i<=x*y;i++)
		{
			if(a[i]<a[i+1])
			{
				int cc=a[i];
				a[i]=a[i+1];
				a[i+1]=cc;
			}
		}
	}
	for(int i=1;i<=x*y;i++)
	{
		if(a[i]==m)
		{
			z=i;
			break;
		}
	}
	if(z%x==0)
	{
		if((z/x)%2!=0)
		{
			cout<<z/x<<" "<<x;
		}
		else
		{
			cout<<z/x<<" "<<1;
		}
	}
	else{
		if((z/x)%2==0)
		{
				
			cout<<z/x+1<<" "<<z%x;
		}
		else
		{
			cout<<z/x+1<<" "<<x-z%x+1;
		}
	}
	return 0;
}
