#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m; 
	cin>>n>>m;
	
	
	int s[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	
	int grade = s[1];
	int pm;
	
	int box=0;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(s[j]<s[j+1])
			{
				box = s[j];
				s[j]=s[j+1];
				s[j+1]=box;
			}
		}
	}
	
	
	for(int i=1;i<=n*m;i++)
	{
		if(s[i] == grade)
		{
			pm = i;
			break;
		}
	}
	
	
	int c,r;
	if(pm%n==0)
	{
		c=pm/n;
		if(c%2==0)
		{
			r = 1;
		}
		else
		{
			r = n;
		}
	}
	else
	{
		c=(pm/n)+1;
		if(c%2==0)
		{
			r = n-(pm%n)+1;
		}
		else
		{
			r = pm%n;
		}
	}
	
	
	cout<<c<<r;
	return 0; 
}
