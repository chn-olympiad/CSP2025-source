#include<bits/stdc++.h>
using namespace std;
long long n,m=0,k,c[5005],b[5005],d[5005],ans=0;
int dfs(int x,int y,int z,int sum,int a)
{
	if(x==z-1)
	{
		if(sum>c[y])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int s=0;
	for(int i=a+1;i<y;i++)
	{
		if(d[i]==0)
		{
			d[i]=1;
			s+=dfs(x+1,y,z,sum+c[i],i);
			d[i]=0;
		}
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		b[c[i]]++;
	}
	sort(c+1,c+n+1);
	for(int k=3;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			ans+=dfs(0,i,k,0,0);
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
