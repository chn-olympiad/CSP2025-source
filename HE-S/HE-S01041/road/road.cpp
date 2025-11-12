#include  <bits/stdc++.h>
using namespace std;
long long a[10050],b[10050],c[10050],d[10050],e[10050],f[10050],g[10050],h[10050],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++)cin>>d[i]>>e[i]>>f[i]>>g[i]>>h[i];
	if(k==0)
	{
		sort(c+1,c+m+1);
		for(int i=1;i<=n-1;i++)ans+=c[i];
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=k;i++)c[m+i]=d[i]+e[i]+g[i];
		sort(c+1,c+m+k+1);
		for(int i=1;i<=n-1;i++)ans+=c[i];
		cout<<ans;
		return 0;
	}
 	return 0;
}

