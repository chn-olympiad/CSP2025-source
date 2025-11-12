#include<bits/stdc++.h>
using namespace std;
int a[5010];
int MOD=998244353;
bool b[5010];
int n;
long long s;
void dfs(int dep,long long sum,long long maxn,int first)
{
	if(dep>3)if(sum>maxn)s=(s+1)%MOD;
	if(dep>n)return;
	for(int i=first;i<=n;i++)
	{
		if(b[i]==false)
		{
			b[i]=true;
			dfs(dep+1,sum+a[i],a[i]*2,i);
			b[i]=false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool st=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)st=false;
	}
	if(st==true)
	{
		long long sum=1,k=0;
		for(int i=3;i<=n;i++)
		{
			sum=1;
			for(int j=1;j<=i;j++)sum=(sum*(n-j+1)/j)%MOD;
			k=(k+sum)%MOD;
		}
		cout<<k<<endl;
		return 0;
	}
	if(n<3)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	dfs(1,0,0,1);
	cout<<s<<endl;
	return 0;
}
