#include<bits/stdc++.h>
using namespace std;

struct node{
	int u;
	int v;
	int w;
}a[1000016];


long long ans=0x7f,ans2=0x7f;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		int r;
		cin>>r;
		long long t=r;
		for(int j=1;j<=n;j++)
		{
			cin>>a[m+i].w;
			t+=a[m+i].w;
		}
		ans2=min(t,ans2);
	}
	cout<<min(ans,ans2);
	
	
	
	
	return 0;
}



