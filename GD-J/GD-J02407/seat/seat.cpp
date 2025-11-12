#include <bits/stdc++.h>
using namespace std;

long long n,m,c,r,a[105];

bool cmp(long long x,long long y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;i++)
	{
		if(a[i]==a[0])
		{
			r=i;
			break;
		}
	}
	cout<<(r+n-1)/n<<" ";
	if((r+n-1)/n%2==0)
	{
		if(r%n==0)
		{
			cout<<1; 
		}
		else
		{
			cout<<(n+1)-r%n;
		}
	}
	else
	{
		if(r%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<r%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
