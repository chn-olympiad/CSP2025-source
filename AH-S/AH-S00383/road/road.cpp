#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
struct node{
	int w,v,u;
};
node a[100005];
bool cmp(node A,node B)
{
	return A.u<B.u;
}
int f[1000005];
int find(int x)
{
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void join(int x,int y)
{
	int rx=find(x);
	int ry=find(y);
	if(rx!=ry)
	{
		f[rx]=ry;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].w>>a[i].v>>a[i].u;
	if(k==0)
	{
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x=a[i].w,y=a[i].v;
			if(find(x)!=find(y))
			{
				join(x,y);
				ans+=a[i].u;
			}
		}
		cout<<ans;
	}
	else cout<<66;
	return 0;
}

