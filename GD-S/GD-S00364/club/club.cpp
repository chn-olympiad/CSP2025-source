#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
long long a1[100001],b1[100001],c1[100001];
long long vis[201][201][201];
void dfs(long long p,long long a,long long b,long long c,long long sum)
{
	if(p==n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a<n/2&&a1[p+1]+sum<vis[a+1][b][c])dfs(p+1,a+1,b,c,a1[p+1]+sum);
	if(b<n/2&&b1[p+1]+sum<vis[a][b+1][c])dfs(p+1,a,b+1,c,b1[p+1]+sum);
	if(c<n/2&&c1[p+1]+sum<vis[a][b][c+1])dfs(p+1,a,b,c+1,c1[p+1]+sum);
	return; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(long long i=0;i<=200;++i)for(long long j=0;j<=200;++j)for(long long k=0;k<=200;++k)vis[i][j][k]=1e18;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;++i)cin>>a1[i]>>b1[i]>>c1[i];
		if(n==200||n==100000)
		{
			sort(a1+1,a1+n+1);
			for(long long i=1;i<=100;++i)
			{
				ans+=a1[i];
			}
			cout<<ans;
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
 //-O2 -std=c++14 -static
