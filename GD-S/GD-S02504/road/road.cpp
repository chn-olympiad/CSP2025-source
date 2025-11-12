#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,city1[N],morepath,onlypath,maxpath,twopath;
long long sum;
struct stu{
	int u,v,co;
	long long w;
}city[N];
struct stu1{
	int c,a[N];
}town[20];
void f()
{
	for(int i=1;i<=n;i++)
	{
		if(city1[i]!=1)morepath++;//路径唯一 
		else onlypath++;
		if(city1[i]!=2)twopath=-1;
		
	}
	//if(twopath!=-1)printf("%lld",sum);//全部度为2 
	//if(ol!=-1&&k==0)printf("%lld",sum);
	 if(k==0){
	//	printf("%d %d\n",onlypath,morepath);
		if(m-onlypath==morepath)//比最小连通图大一，找到非路径唯一的点的最大价值 
		{
			for(int i=1;i<=m;i++)
			{
				
				if(city1[city[i].u]!=1&&city1[city[i].v]!=1)
				{
					if(city[i].w>=maxpath)maxpath=city[i].w;
					//cout<<maxpath<<" ";
				}
			}
			sum-=maxpath;
			printf("%lld",sum); 
		}
		
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&city[i].u,&city[i].v,&city[i].w);
		city1[city[i].u]++;
		city1[city[i].v]++;
		sum+=city[i].w;
	}
	for(int j=1;j<=k;j++)
	{
		scanf("%d",&town[j].c);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",town[i].a);
		}
	}
	f();
	return 0;
}
