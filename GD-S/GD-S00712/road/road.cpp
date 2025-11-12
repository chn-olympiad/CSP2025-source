#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[1001000];
int c[10010],d[20][10010];
int n,m,cnt,k,ans,fa[10010];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1)
		{
			break;
		}
		int x=a[i].x,y=a[i].y;
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy)
		{
			cnt++;
			ans+=a[i].z;
			fa[fx]=fy;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Ren5Jie4Di4Ling5%
