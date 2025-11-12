#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long visit[500010];
long long answer=0;
bool check(long long l,long long r)
{
	for(long long aaa=l;aaa<=r;aaa++)
	{
		if(visit[aaa]==1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(i==j&&check(i,j)==true&&a[i]==k)
			{
				answer+=1;
				visit[i]=1;
			}
			else
			{
				long long sum_temp=0;
				for(long long kf=i+1;kf<=j;kf++)
				{
					sum_temp+=!(a[kf]|a[kf-1]);
				}
				if(sum_temp==k&&check(i,j)==true)
				{
					for(long long fgfg=i;fgfg<=j;fgfg++)
					{
						visit[fgfg]=1;
					}
					answer+=1;
				}
			}
		}
	}
	cout<<answer*2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
