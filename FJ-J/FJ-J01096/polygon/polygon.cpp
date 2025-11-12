#include<bits/stdc++.h>
using namespace std;
long long N=998244353,ans,n;
long long a[50000];
void dfs(int step,long long s,long long maxx,int last)
{
	if(step>3)
	{
		if(s>2*maxx)
		{
			ans++;
			ans=ans%N;
		}
	}
	for(int i=last+1;i<=n;i++)
	{
		dfs(step+1,s+a[i],max(maxx,a[i]),i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			flag=1;
	}
	if(flag==0)
	{
		long long k=n*(n-1),kk=1*2;
		for(int i=n-2;i>=1;i--)
		{
			k=k*i;
			k=k%N;
			kk=kk*(n-i+1);
			kk=kk%N;
			ans+=k/kk;
			ans=ans%N;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

