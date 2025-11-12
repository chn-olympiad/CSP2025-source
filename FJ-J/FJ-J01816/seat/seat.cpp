#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int b;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			b=a[1];
			
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			b=i;
	
			break;
		}
		//cout<<a[i];
	}
	
	if(b%n>0)
	{
		cout<<b/n+1<<" ";
		if(b/n%2==0)
		{
			cout<<b%m;
		}
		else
		{
			cout<<m-b%m+1;
		}
	}
	else
	{
		cout<<b/n<<" ";
		if(b/n%2==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<m;
		}
	}
	return 0;
}
