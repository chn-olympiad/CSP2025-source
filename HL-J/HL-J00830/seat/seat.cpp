#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[105];
	int t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	int d=0;
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++)
	{
		if(a[i]==r)
		{
			d=i;	
		}
	}
	int k=t+1-d;
	int lie=0;
	if(k%n!=0)
	{
		cout<<k/n+1<<" ";
		lie=k/n+1;
	}
	else
	{
		cout<<k/n<<" ";
		lie=k/n;
	}
	if(lie%2==1)//ÆæÊýÁÐ 
	{
		if(k%n!=0)
		{
			cout<<k%n;
		}
		else 
		{
			cout<<n;
		}
		
	}
	else 
	{
		int temp=k%n;
		if(k%n!=0)
		{
			cout<<n+1-temp;
		}
		else
		{
			cout<<1;
		}
		
	}
	return 0;
}

