#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	if(r%n==0)
	{
		cout<<r/n<<" ";
		if(r/n%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}	
	}
	else
	{
		cout<<r/n+1<<" ";
		if((r/n+1)%2==1)
		{
			cout<<r%n;
		}
		else
		{
			cout<<n-r%n+1;
		}
	}
	return 0;
}