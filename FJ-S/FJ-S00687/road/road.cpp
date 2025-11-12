#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
struct node
{
	int u,v,w;
}a[100005];
struct xz
{
	int c;
	int b[10005];
}x[15];
bool cmp(node xx, node yy)
{
	return xx.w < yy.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)	
		cin>>a[i].u>>a[i].v>>a[i].w;
		
	for(int i=1; i<=k; i++)
	{
		cin>>x[i].c;
		for(int j=1; j<=n; j++)
			cin>>x[i].b[j];
	}
	
	if(k == 0)
	{
		sort(a+1,a+1+m,cmp);
		for(int i=1; i<n; i++)
			ans+=a[i].w;
	}
	else
	{
		for(int i=1; i<=m; i++)	
			ans+=a[i].w;
			
		for(int i=1; i<=k; i++)
		{
			if(x[i].c != 0)
				continue;
				
			int sum=0;
			for(int j=1; j<=n; j++)
				sum+=x[i].b[j];
				
			ans=min(ans,sum);
		}
	}
	
	cout<<ans;
	
	return 0;
}
