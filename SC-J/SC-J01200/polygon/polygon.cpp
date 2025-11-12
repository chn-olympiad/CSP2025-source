#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long ans=0;
void dfs(long long x,long long id,long long now,long long sum,long long maxx)
{
	if(x==id)
	{
		if(sum>maxx*2)
		{
			ans++;
			ans%=998244353;
//			cout<<x<<" "<<sum<<" "<<maxx<<endl;
		}
		
	}
	else
	{
		for(int i=now;i<=n;i++)
		{
			dfs(x,id+1,i+1,sum+a[i],max(maxx,a[i]));
		}
	}
}
long long c(long long x,long long y)
{
	long long t=1;
	for(int i=x+1;i<=y;i++)
	{
		t*=i;
		t%=998244353;
	}
	for(int i=1;i<=y-x;i++)
	{
		t/=i;
		t%=998244353;
	}
	return t;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	long long pf=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pf=max(pf,a[i]);
	}
	if(pf==1)//pf!! 
	{
		long long tans=0;
		for(int i=3;i<=n;i++)
		{
			tans+=c(i,n)%998244353;
		}
		cout<<tans<<endl;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
	//		for(int j=1;j<=n-i+1;j++)
			{
				dfs(i,0,1,0,0);
			}
		}
		cout<<ans;
	}
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}