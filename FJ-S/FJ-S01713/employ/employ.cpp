#include<bits/stdc++.h>
using namespace std;

int n,m,a[500],b[500],v[500],sta[500],h=0,ans;

void dfs(int nw)
{
	if(nw==n+1)
	{
		int lq=0,wlq=0;
		for(int i=1;i<=n;i++)
		{
			if(wlq>=b[sta[i]])
			{
				wlq++;continue;
			} 
			if(a[i]==0) wlq++;
			if(a[i]) lq++;
			if(lq>=m) break;
		}
		if(lq>=m) ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i]) 
		{
			sta[++h]=i;
			v[i]=1;
			dfs(nw+1);
			h--;
			v[i]=0;	
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int fl=0,ti=n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=c-'0';
		if(a[i]==1) fl++;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i];
		if(b[i]==0) ti--;
	}
	if(n==m&&fl!=n)
	{
		cout<<0;
		return 0;
	}
	if(ti+1<m)
	{
		cout<<0;
		return 0;
	}
	if(fl==n)
	{
		long long k=1;
		for(int i=n;i>=1;i--) k=k*i%998244353;
		cout<<k;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}