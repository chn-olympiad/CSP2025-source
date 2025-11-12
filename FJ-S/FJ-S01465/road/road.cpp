#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10004],l,gk[25],c[10005],ans,cnt,sn,minn=9999999,lt=0;
int o[1000000];
struct node
{
	int x,y,z;
	bool f;
}a[3000300];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int find(int ez)
{
	if(fa[ez]==ez) return ez;
	else fa[ez]=find(fa[ez]);
	return fa[ez];
}
bool hb(int x,int y)
{
	int mm,nn;
	mm=fa[x];
	nn=fa[y];
	if(mm!=nn)
	{
		mm=find(nn);
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>gk[i];
		minn=min(gk[i],minn);
		for(int j=1;j<=n;j++)
		{
			cin>>c[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i].x==j||a[i].y==j)
			o[j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(o[i]==0)
		lt=0;
	}
	if(lt==1)
	{
		cout<<"0";
	}
	else
	cout<<minn;
	return 0;
}
