//GZ-S00124 贵阳市白云区华师一学校 姜裕伟
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct aa
{
	int a[1005];
}a[1005];
map<pair<int,int>,bool> ma; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	n=min(1000,n);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u].a[v]=w;
		a[v].a[u]=w;
	}
	bool bbb=1;
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		int aa[1005];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&aa[i]);
			if(aa[i]!=0) bbb=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				a[i].a[j]=min(a[i].a[j],x+aa[i]+aa[j]);
			}
		}
	}
	if(bbb)
	{
		cout<<"0";
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int s=INT_MAX,id;
		for(int j=1;j<=n;j++)
		{
			if(a[i].a[j]==0) continue;
			if(ma[{i,j}]==1||ma[{j,i}]==1) continue;
			if(a[i].a[j]<s)
			{
				s=a[i].a[j];
				id=j;
			}
		}
		if(s==INT_MAX) s=0;
		ma[{i,id}]=1;
		ans+=s;
	}
	printf("%d",ans);
	return 0;
}

