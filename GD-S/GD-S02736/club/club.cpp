#include<bits/stdc++.h>
using namespace std;

int t;
long long n;

struct ls
{
	
	long long a, b, c;
	
};

vector<ls> op;

int main()
{
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin>>t;
	
	while(t--)
	{
		
		op.clear();
		
		cin>>n;
		
		op.resize(n);
		
		for(int i=0;i<n;i++)
		{
			
			cin>>op[i].a>>op[i].b>>op[i].c;
			
		}
		
		map<pair<pair<long long, long long>, pair<long long, long long>>, long long> dp;
		
		for(int i=1;i<=n;i++)
		{
			
			for(int j=0;j<=n/2;j++)
			{
				
				for(int k=0;k<=n/2&&k<=i-j;k++)
				{
					
					if(i-j-k>n/2)
					{
						
						continue;
						
					}
					
					if(dp.find({{i-1, j-1}, {k, i-j-k}})==dp.end())
					{
						
						dp[{{i-1, j-1}, {k, i-j-k}}]=0;
						
					}
					if(dp.find({{i-1, j}, {k-1, i-j-k}})==dp.end())
					{
						
						dp[{{i-1, j}, {k-1, i-j-k}}]=0;
						
					}
					if(dp.find({{i-1, j}, {k, i-j-k-1}})==dp.end())
					{
						
						dp[{{i-1, j}, {k, i-j-k-1}}]=0;
						
					}
					
					if(j==0)
					{
						
						if(k==0)
						{
							
							dp[{{i, j}, {k, i-j-k}}]=dp[{{i-1, j}, {k, i-j-k-1}}]+op[i-1].c;
							
						}
						else if(i-j-k==0)
						{
							
							dp[{{i, j}, {k, i-j-k}}]=dp[{{i-1, j}, {k-1, i-j-k}}]+op[i-1].b;
							
						}
						else
						{
							
							dp[{{i, j}, {k, i-j-k}}]=max(dp[{{i-1, j}, {k-1, i-j-k}}]+op[i-1].b, dp[{{i-1, j}, {k-1, i-j-k-1}}]+op[i-1].c);
							
						}
						
						continue;
						
					}
					else if(k==0)
					{
						
						if(i-j-k==0)
						{
							
							dp[{{i, j}, {k, i-j-k}}]=dp[{{i-1, j-1}, {k, i-j-k}}]+op[i-1].a;
							
						}
						else
						{
							
							dp[{{i, j}, {k, i-j-k}}]=max(dp[{{i-1, j-1}, {k, i-j-k}}]+op[i-1].a, dp[{{i-1, j}, {k, i-j-k-1}}]+op[i-1].c);
							
						}
						
						continue;
						
					}
					
					dp[{{i, j}, {k, i-j-k}}]=max(max(dp[{{i-1, j-1}, {k, i-j-k}}]+op[i-1].a, dp[{{i-1, j}, {k-1, i-j-k}}]+op[i-1].b), dp[{{i-1, j}, {k, i-j-k-1}}]+op[i-1].c);
					
					//cout<<i<<' '<<j<<' '<<k<<' '<<i-j-k<<"  "<<dp[{{i, j}, {k, i-j-k}}]<<endl;
					
				}
				
			}
			
		}
		
		long long MAX=0;
		
		for(long long i=0;i<=n/2;i++)
		{
			
			for(long long j=0;j<=n/2&&j<=n-i;j++)
			{
				
				if(n-i-j>n/2)
				{
					
					continue;
					
				} 
				
				MAX=max(MAX, dp[{{n, i}, {j, n-i-j}}]);
				
			}
			
		}
		
		//cout<<dp[{{2, 1}, {1, 0}}]<<" "<<dp[{{1, 0}, {1, 0}}]<<endl;
		
		cout<<MAX<<endl;
		
	}
	
	return 0;
	
} 
