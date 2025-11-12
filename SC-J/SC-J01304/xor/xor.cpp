#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,ma=0;
struct node
{
	long long x[600000];
	long long si;
}t[2];
queue<node> q;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(long long i=1;i<=a;i=i+1)
	{
		cin>>t[1].x[i];
	}
	t[1].si=a;
	q.push(t[1]);
	while(q.empty()!=1)
	{
		int cl=0;
		for(long long i=0;i<=q.front().si-1;i=i+1)
		{
			for(long long j=1;j+i<=q.front().si;j=j+1)
			{
				long long s=0;
				for(long long k=j;k<=j+i;k=k+1)
				{
					s=s+q.front().x[k];
				}
				if((s-b)%2==1 || b>s)
				{
					continue;
				}
				s=(s-b)/2;
				long long dp[s+2];
				memset(dp,0,sizeof(dp));
				for(long long k=1;k<=s;k=k+1)
				{
					for(long long l=j;l<=j+i;l=l+1)
					{
						/*if(dp[k]==0)
						{
							dp[k]=dp[k-1];
						}*/
						if(q.front().x[l]<=k)
						{
							dp[k]=max(dp[k],dp[k-q.front().x[l]]+q.front().x[l]);
						}
					}
				}
				if(dp[s]==s)
				{
					ma=ma+1;
				}
				else
				{
					continue;
				}
				long long zs=0;
				memset(t[1].x,0,sizeof(t[1].x));
				for(long long k=1;k<=j-1;k=k+1)
				{
					zs=zs+1;
					t[1].x[zs]=q.front().x[k];
				}
				t[1].si=zs;
				q.push(t[1]);
				zs=0;
				memset(t[1].x,0,sizeof(t[1].x));
				for(long long k=j+i+1;k<=q.front().si;k=k+1)
				{
					zs=zs+1;
					t[1].x[zs]=q.front().x[k];
				}
				t[1].si=zs;
				q.push(t[1]);
				cl=1;
				break;
			}
			if(cl==1)
			{
				break;
			}
		}
		q.pop();
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}