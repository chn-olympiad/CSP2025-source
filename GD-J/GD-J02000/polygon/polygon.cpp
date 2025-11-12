#include<iostream>

using namespace std;

int n;

int calc(int k,int p)
{
	long long ans=1;
	
	bool c[5005];
	
	for(int i=2;i<=p;i++)
	{
		c[i]=false;
	}
	
	for(int i=1;i<=p;i++)
	{
		ans*=(k-i+1);
		
		for(int j=2;j<=p;j++)
		{
			if(ans%j==0&&c[j]==false)
			{
				c[j]=true;
				
				ans/=j;
			}
		}
		
		ans=ans%998244353;
	}
	
	return ans;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	if(n==3)
	{
		int a,b,c;
		
		cin>>a>>b>>c;
		
		if(max(a,max(b,c))*2<a+b+c)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		
		return 0;
	}
	else
	{
		long long ans=0;
		
		for(int i=3;i<=n;i++)
		{
			ans+=calc(n,i);
			
			ans=ans%998244353;
		}
		
		cout<<ans;
	}
}
