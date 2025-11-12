#include<bits/stdc++.h>
using namespace std;
long long a[15];
long long path[15],visit[15];
long long n;
long long minnute[11]={0,1,2,6,24,120,720,5040,40320,362880,3628800};
long long dfs(long long f,long long goal)
{
	if(f==goal)
	{
		long long ans=a[path[1]],sum=0;
		for(int i=0;i<f;i++)
		{
			ans=max(ans,a[path[i]]);
			sum+=a[path[i]];
			
			
		}
		
		if(sum>2*ans)
		{
			return 1;
		}
		else{
			return 0;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==0)
		{
			path[f]=i;
			visit[i]=1;
			ans+=dfs(f+1,goal);
			visit[i]=0;
			
		}
	}
	return ans;
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon,out","w",stdout);
	
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
			
		int a,b,c;
		cin>>a>>b>>c;
		int ans=max(a,b);
		ans=max(ans,c);
		if(a+b+c>ans)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		long long a=dfs(0,i)/minnute[i];
		ans+=a;
	}
	cout<<ans;
	return 0;
}
