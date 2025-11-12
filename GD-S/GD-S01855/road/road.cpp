#include<bits/stdc++.h>
using namespace std;//zuixiaoshengchengshu
int n,m,k;
struct node{
	int u,v,w;
}a[1100005];
struct node2{
	int aj[10005],c;
}kt[15];
struct node3{
	int father,num=1;
}point[10005];
bool cmp(node aaa,node bbb)
{
	return aaa.w<bbb.w;
}
int findfa(int x)
{
	if(point[x].father!=x) point[x].father=findfa(point[x].father);
	return point[x].father;
}
void mixt(int aaa,int bbb)
{
	int fa1=findfa(aaa),fa2=findfa(bbb);
	point[fa1].father=fa2;
	point[fa2].num+=point[fa1].num; 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	point[i].father=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&kt[i].c);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&kt[i].aj[j]);
		}
	}
	if(k==0)
	{
		sort(a+1,a+1+m,cmp);
		long long ans=0;
		for(int i=1;i<=m;i++)
		{
			if(findfa(a[i].u)!=findfa(a[i].v))
			{
				mixt(a[i].u,a[i].v);
				ans+=a[i].w;
//				cout<<a[i].w<<" "<<point[findfa(a[i].v)].num<<endl;
				if(point[findfa(a[i].v)].num==n)
				break;
			}
		}
		printf("%lld",ans);
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			if(kt[i].c==0)
			{
				for(int j=1;j<=n;j++)
				{
					if(kt[i].aj[j]==0)
					{
						for(int p=1;p<=n;p++)
						{
							m++;
							a[m].u=j;
							a[m].v=p;
							a[m].w=kt[i].aj[p];
						}
					}
				}
			}
		}
		sort(a+1,a+1+m,cmp);
		long long ans=0;
		for(int i=1;i<=m;i++)
		{
			if(findfa(a[i].u)!=findfa(a[i].v))
			{
				mixt(a[i].u,a[i].v);
				ans+=a[i].w;
//				cout<<a[i].w<<" "<<point[findfa(a[i].v)].num<<endl;
				if(point[findfa(a[i].v)].num==n)
				break;
			}
		}
		printf("%lld",ans);
	}
	return 0;
} 
