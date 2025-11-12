#include <bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,cnt,m,xxx;
long long a[5005],b[5005];
bool cmp(long long aa,long long bb)
{
	return aa<bb;
}
long long jc(long long x)
{
	if(b[x]) return b[x];
	long long s=1;
	for(int i=1;i<=x;++i)
	{
		s=s*i%Mod;
	}
	b[x]=s;
	return s;
}
void dfs(long long sum,int id,int lon,int f)
{
	for(int i=id+1;i<=n;++i)
	{
		if(sum>a[i]) cnt++; 
		dfs(sum+a[i],i,lon+1,i);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]==1) xxx++;
	}
	if(xxx==n)
	{
		long long ans=jc(n);
		for(int i=3;i<=n;++i)
		{
			cnt=(cnt+ans/jc(i)/jc(n-i))%Mod;
		}
	}
	else
	{
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n-2;++i)
		{
			for(int j=i+1;j<=n-1;++j)
			{
				dfs(a[i]+a[j],j,2,j);
				cnt%=Mod
			}
		}
	}
	cout<<cnt%Mod<<"\n";
	return 0;
}
