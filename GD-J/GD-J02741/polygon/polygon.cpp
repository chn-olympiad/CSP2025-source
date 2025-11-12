#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans[5005][2],k,bz[5005],task[5005];
long long cnt,tot;
void dfs(int x,int d,int y)
{
	if(x==0&&tot>task[d-1]*2)
	{
		cnt++;
		cnt%=998244353;
	}
	else
	{
		for(int i=y;i<=n;i++)
		{
			if(!bz[i])
			{
				bz[i]=1;
				task[d]=a[i];
				tot+=a[i];
				dfs(x-1,d+1,i);
				bz[i]=0;
				task[d]=0;
				tot-=a[i];
			}
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			long long ans=1;
			for(int j=i+1;i<=n;i++)
			{
				ans*=j;
				ans%=998244353;
			}
			cnt+=ans;
		}
		cout<<cnt;
		return 0;
	}
	if(tot>a[n]*2) cnt++;
	tot=0;
	for(int i=3;i<n;i++)
	{
		dfs(i,1,1);
	}
	cout<<cnt;
	return 0;
}
