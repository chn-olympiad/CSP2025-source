#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,f[10005]={0},s[10005][10005],e,p = 0;
	std::cin>>n>>m;
	std::cin>>e;
	long long r = n*m;
	long long c = 0;
	for(long long i = 1;i<r;i++)
	{
		std::cin>>f[i];	
	}
	f[0] = e;
	std::sort(f,f+r,cmp);
	for(long long i = 0;i<r;i++)
	{
		if(f[i]==e)
		{
			e = i;
		}
	}
	for(long long i = 0;i<m;i++)
	{
		if(i%2 == 0)
		{
			for(long long j = 0;j<n;j++)
			{
				if(c == e)
				{
					std::cout<<i+1<<" "<<j+1;
					p = 1;
					break;
				}
				c++;
			}
		}
		else
		{
			for(long long j = n-1;j>=0;j--)
			{
				if(c == e)
				{
					std::cout<<i+1<<" "<<j+1;
					p = 1;
					break;
				}
				c++;
			}
		}
		if(p == 1)
		{
			break;
		}
	}
	return 0;
}
