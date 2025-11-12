#include<bits/stdc++.h>
using namespace std;

int n;
long long a[5007];

long long cnt;
const long long MOD=998244353;

void dfs(int now, int MAX, long long sum)
{
	
	if(sum>MAX*2)
	{
		
		cnt++;
		cnt%=MOD;
		
	}
	
	for(int i=now+1;i<=n;i++)
	{
		
		if(a[i]>MAX)
		{
			
			dfs(i, a[i], sum+a[i]);
			
		}
		else
		{
			
			dfs(i, MAX, sum+a[i]);
			
		}
		
	}
	
	return;
	
}

int main()
{
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin>>n;
	
	long long zui=0;
	
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		zui=max(zui, a[i]);
		
	}
	
	if(zui==1)
	{
		
		long long an=0;
		
		for(int i=3;i<=n;i++)
		{
			
			long long cu=1;
			
			for(int j=n;j>n-i;j--)
			{
				
				cu*=j;
				cu%=MOD; 
				
			}
			
			for(int j=2;j<=i;j++)
			{
				
				cu/=j;
				
			}
			
			an+=cu;
			an%=MOD;
			
		}
		
		cout<<an;
		
		return 0;
		
	}
	
	for(int i=1;i<=n;i++)
	{
		
		dfs(i, a[i], a[i]);
		
	}
	
	cout<<cnt%MOD;
	
	return 0;
	
}
