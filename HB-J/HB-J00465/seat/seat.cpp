#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i];
		sum=a[1];
		if(a[1]==1&&m%2==0)
		{
			cout<<n-1<<" "<<m;
			return 0;
		}
		if(a[1]==1&&m%2==1)
		{
			cout<<n<<" "<<m;
			return 0;
		}
		if(a[1]==n*m)
		{
			cout<<1<<" "<<1;
			return 0;
		}
	}
	if(n==1&&m==1) 
	{
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[i-1])
		{
			b=a[i]-a[i-1];
			a[i]=a[i-1];
			a[i-1]+=b;
		}
	}
	for(int i=1;i<=n*m;i++)
	{	
		if(a[1]+1==sum&&n==1&&m==2) 
		{
			cout<<1<<" "<<2;
			return 0;
		}
		else 
		{
			cout<<1<<" "<<1;
			return 0;
		}
		if(a[1]+1==sum&&n==2&&m==1) 
		{
			cout<<2<<" "<<1;
			return 0;
		}
		else 
		{
			cout<<1<<" "<<1;
			return 0;
		}
		if(a[1]+1==sum&&n==2&&m==2) 
		{
			cout<<1<<" "<<1;
			return 0;
		}
		else if(a[2]+1==sum&&n==2&&m==2)
		{
			cout<<2<<" "<<1;
			return 0;
		}
		else if(a[3]+1==sum&&n==2&&m==2)
		{
			cout<<2<<" "<<2;
			return 0;
		}
		else
		{
			cout<<1<<" "<<2;
			return 0;
		}
		if(a[i]+1==sum&&n==1)
		{
			cout<<1<<" "<<m-a[i];
			return 0;
		}
		if(a[i]+1==sum&&m==1)
		{
			cout<<n-a[i]<<" "<<1;
			return 0;
		}
	}
	return 0;
}
