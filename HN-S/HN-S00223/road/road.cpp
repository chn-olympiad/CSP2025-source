#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans=0;
int cnt=0;
int f[15];
struct qwq
{
	int u,v,w;
	int flag;
}a[1145145];
int father[10005];
void init()
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
}
int find(int x)
{
	if(father[x]!=x)
	{
		father[x]=find(father[x]);
	}
	return father[x];
}
void hb(int x,int y)
{
	int rootx=find(x);
	int rooty=find(y);
	if(rooty==rootx)
	{
		return;
	}
	father[rootx]=rooty;
}
int cmp(qwq x,qwq y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int e=1;e<=k;e++)
	{
		cin>>f[e];
		int asa[10005];
		for(int i=1;i<=n;i++)
		{
			cin>>asa[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				a[++m].u=i;
				a[m].v=j;
				a[m].w=asa[i]+asa[j];
				a[m].flag=e;
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			cout<<a[i].u<<" "<<a[i].v<<endl;
			ans+=a[i].w;
			cnt++;
			hb(a[i].u,a[i].v);
		}
		if(cnt==n-1)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
