#include<bits/stdc++.h>
using namespace std;
int n,a[114514];
bool b=1;
const int MOD=998244353;
long long A1(long long lzq)
{
	long long ss=1;
	for(int z=1;z<=lzq;z++)
	{
		ss*=z;
		ss%=MOD;
	}
	return ss;
}
long long sum=0;
void dfs(long long s,long long t,long long now,long long lzq)
{
	if(lzq==t)
	{
		if(s>a[now]*2)
		{
			sum++;
		}
	}
	else
	{
		for(int z=now+1;z<=n;z++)
		{
			dfs(s+a[z],t,z,lzq+1);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int z=1;z<=n;z++)
	{
		cin>>a[z];
		if(a[z]!=1)
		{
			b=0;
		}
	}
	sort(a+1,a+n+1);
	if(b==1)
	{
		for(int z=3;z<=n;z++)
		{
			sum+=A1(n)/(A1(n-z)*A1(z));
			sum%=MOD;
		}
	}
	else if(n<=2)
	{
		sum=0;
	}
	else if(n==3)
	{
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])
		{
			sum=1;
		}
		else
		{
			sum=0;
		}
	}
	else
	{
		for(int z=3;z<=n;z++)
		{
			dfs(0,z,0,0);
		}
	}
	cout<<sum;
	return 0;
}
