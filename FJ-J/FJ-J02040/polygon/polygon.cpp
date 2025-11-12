#include<bits/stdc++.h>
using namespace std;
int n;
int a[5011];
int b[5011];
long long qi[5011];
int ans;
int maxz=-1;
int maxx=-1;
int ss=0;
long long sz=0;
inline void dfs(int dep)
{
	if(dep==n+1)
	{
		sz=0;
		for(int k(1); k<=ss; k++)
		{
			if(b[k]>maxx)
				maxx=b[k];
			sz+=b[k];
		}
		if(sz>maxx*2&&ss>=3)
		{
			ans++;
		}
		ans%=998244353;
		return;
	}
	ss++;
	b[ss]=a[dep];
	dfs(dep+1);
	ss--;
	b[ss]=0;
	dfs(dep+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i(1); i<=n; i++)
	{
		cin>>a[i];
		if(a[i]>maxz)
			maxz=a[i];
	}
	if(n<=2)
	{
		cout<<0<<"\n";
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(maxz==1)
	{
		cout<<(n-1)*(n-2)/2;
		return 0;
	}
    dfs(1);
	cout<<ans%998244353;
	return 0;
}

