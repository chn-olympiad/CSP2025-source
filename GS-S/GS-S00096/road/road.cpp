#include <bits/stdc++.h>
using namespace std;
struct lu{
	int u;
	int v;
	int w;
}fy[1000001];
int a[10000001];
int b[1000001];
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>fy[i].u>>fy[i].v>>fy[i].w;
		b[i]=fy[i].w;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>a[j];	
		}
	}
	sort(b,b+m);
	for(int i=0;i<m;i++)
	{
		ans+=b[i];
	}
	cout<<ans-b[m-1];
	return 0;
}
