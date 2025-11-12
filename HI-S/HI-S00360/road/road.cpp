#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[19],a[19][10009],pd[1000009],ans;
struct str
{
	long long u,v,w;
}ro[1000008];
bool cmp(str x,str y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++) cin>>ro[i].u>>ro[i].v>>ro[i].w;
	for(int i=0;i<k;i++)
	{
		bool flag=0;
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0) flag=1;
		}
		if(!flag)
		{
			cout<<c[i];
			return 0;
		}
	}
	if(k==0)
	{
		sort(ro,ro+m,cmp);
		for(int i=0;i<m;i++)
		{
			if(pd[ro[i].u]==0 || pd[ro[i].v]==0)
			{
				ans+=ro[i].w;
				pd[ro[i].u]=1;
				pd[ro[i].v]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

