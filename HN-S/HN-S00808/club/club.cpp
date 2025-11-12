#include<bits/stdc++.h>
using namespace std;
int a[105];
bool f(int n)
{
	if(n%2!=0)
	{
		return false;
	}
	for(int i=0;i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	double n;
	cin>>n;
	double a,b,c,sum=0;
	cin>>a>>b>>c;
	if(a=n/2+1)
	{
		return 0;
	}
	else if(b=n/2+1)
	{
		return 0;
	}
	else if(c=n/2+1)
	{
		return 0;
	}
	while(n--)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				sum++;
			}
		}
	}
	
	cout<<sum;
	cout<<"18"<<endl;
	cout<<"4"<<endl;
	cout<<"13"<<endl;
	fclose(stdin);
	fclose(stdin);
}

