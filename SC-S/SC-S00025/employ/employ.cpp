#include<bits/stdc++.h>
using namespace std;
void read(int &n)
{
	n=0;
	char c=getchar();
	while('0'>c or c>'9')c=getchar();
	while('0'<=c and c<='9')
	{
		n=n*10+c-'0';
		c=getchar();
	}
}
bool b[15];
int c[15];
bool vi[15];
int pl[15];
int n,m,ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int tx=0;
		for(int i=1;i<=n;i++)
		{
			//printf("%d ",pl[i]);
			if(!b[i] or tx>=c[pl[i]])
			{
				//printf(":因为b=");
				//cout<<b[i];
				//printf(",tx=%d,c[%d]=%d而退出\n",tx,pl[i],c[pl[i]]);
				tx++;
			}
		}
		//printf("\n");
		if(n-tx>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vi[i])
		{
			vi[i]=1;
			pl[x]=i;
			dfs(x+1);
			vi[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		b[i]=getchar()-'0';
	}
	for(int i=1;i<=n;i++)read(c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*
全都等于1，那么每天都能通过，一定不会有人退出，全排列即可
什么？你说c=0？c=0就直接死了，而且会减少面试者的信心，太难了，我做不出来
然后看录取了人就行，那么我们转化为一个人都没有录取，
一共分数：100+52+25+8
T2:特性A和k=0直接把所有乡村加入，然后最小生成树，k=5，m<=1e5的数据点，克鲁斯卡尔应该能卡过CCF老年机，如果不想每次都排序，可以原来的边只排一次，新加的边单独排序，常数少一点
T3:我应该只会特性B，这个特性直接推狮子
T4:暴力
*/
/*
3 2
101
1 1 2

*/