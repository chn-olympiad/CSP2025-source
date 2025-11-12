#include<bits/stdc++.h>
using namespace std;
int n,m,k;//城市数量,道路数量,乡镇数量
int u,v,w;//u,v链接的城市,w费用
int hd[1000001];
int c[20];//改造费用
long long a[20][1000001];//该乡镇与原有的城市间建造道路的费用
int ans=0;
struct edge{
	int to,w,nxt;
};
edge e[1000001];
int num=0
void add(int from,int to,int w)
{
	num++;
	e[num].to=to;
	e[num].nxt=hd[from];
	e[num].w=w;
	hd[from]=num;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%dll",&a[i][j]);
		}
	}
	if(k==0)
	{
		
	}
	else if(k>0)
	{
		for(int i=1;i<=k;i++)
		{
			int dl=0;
			for(int j=1;j<=n;j++)
			{
				if(c[i]==0&&a[i][j]!=0)
				{
					dl++;
				}
			}
			if(dl==0)
			{
				ans=0;
				printf("%d",ans);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}