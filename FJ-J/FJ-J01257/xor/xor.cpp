#include<bits/stdc++.h>
using namespace std;
long long n,mb,s[500050],sy=0;
long long z(int x,int y)
{
	long long ans=0,yi=1;
	for(int i=x;i<=y;i++)
	{
		long long zh=s[i];
		for(int j=0;j+i<=y;j++)
		{
			if(j!=0)
				zh^=s[i+j];
			if(zh==mb)
			{	
				sy=i+j; 
				if(i==x&&i+j==y)
					ans+=max(yi,z(i+1,i+j));
				else
					ans+=z(i,i+j);
				i=sy;
				break;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&mb);
	for(int i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	printf("%lld",z(1,n));
	return 0;
}

