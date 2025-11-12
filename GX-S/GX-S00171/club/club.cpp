#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100010][4];
long long c[4];
//long long f[20010][4];
long long sum=0;
long long ans=-1;
void dfs(long long i,long long j)
{
	if(i==n+1)
	{
		if(sum>ans) ans=sum;
		return;
	}
	if(c[j]<=m)
	{
		c[j]++;
		sum+=a[i][j];
		if(c[1]<m) dfs(i+1,1);
		if(c[2]<m) dfs(i+1,2);
		if(c[3]<m) dfs(i+1,3);
		c[j]--;
		sum-=a[i][j];
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		m=n/2;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,1);
		dfs(1,2);
		dfs(1,3);
		cout<<ans<<endl;
		ans=-1;
		sum=0;
	}
	return 0;
}
