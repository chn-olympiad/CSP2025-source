#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int w[110000][5];
struct A{
	int sum=0;
	int d=0,id=0;
	bool operator<(const A x)
	{
		return d<x.d;
	}
	void clear()
	{
		sum=id=0;
		d=0x3f3f3f3f;
	}
}a[110000];
int n,vis[5];
void solve()
{
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=3;i++) vis[i]=0; 
	for(int i=1;i<=n;i++)
	{
		a[i].clear();
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&w[i][j]);
//			a[i].sum=max(a[i].sum,w[i][j]);
			if(a[i].sum<w[i][j])
			{
				a[i].sum=w[i][j];
				a[i].id=j;
			}
		}
		vis[a[i].id]++;
		for(int j=1;j<=3;j++)
			if(a[i].id!=j) a[i].d=min(a[i].d,a[i].sum-w[i][j]);
//			else
//			{
//				if(a[i].id!=0) return ;
//				vis[j]++,a[i].id=j;
//			}
		sum+=a[i].sum;
//		printf("##  %d %d %d\n",a[i].sum,a[i].id,a[i].d);
	}
	sort(a+1,a+n+1);
//	printf("%d ",sum);
	for(int i=1;i<=3;i++)
	{
		if(vis[i]>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j].id==i)
				{
//					printf("%d %d %d\n",sum,a[j].d,vis[i]);
					vis[i]--;
					sum-=a[j].d;
				}
				if(vis[i]==n/2) break;
			}
		}
	}
	printf("%d\n",sum);
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q=0;
	scanf("%d",&q);
	while(q--)
	{
		solve();
//		printf("# %d\n",q);
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
