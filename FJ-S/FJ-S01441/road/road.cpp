#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long n,m,k;
int a1=0;
long long ans;
int main()
{
	freeopen("road.in","r",stdin);
	freeopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u[n+1],v[n+1],w[n+1];
	int c[k+1];
	int a[n+1];
	int s[m]={0};
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		s[u[i]]++;s[v[i]]++;
		ans+=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			a[j]+=c[i];
			if(c[i]!=0||a[j]!=0) a1=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m-i;j++)
		{
			if(w[i]<w[i+1])
			{
				swap(w[i],w[i+1]);
				swap(u[i],u[i+1]);
				swap(v[i],v[i+1]);
			}
		}
	}
	if(k!=0&&a1==0) cout<<0;
	for(int i=1;i<=n;i++)
	{
		if(s[u[i]]>1&&s[v[i]]>1) ans-=w[i];
	}
	else cout<<ans;
	return 0;
}
