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
const int N=1e5+5;
int a[N],b[N],c[N];
int qz[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--)
	{
		int n,xa=0,xb=0,xc=0;
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			read(b[i]);
			read(c[i]);
			int maxn=max(a[i],max(b[i],c[i]));
			if(maxn==a[i])
			{
				xa++;
			}
			else if(maxn==b[i])
			{
				xb++;
			}
			else
			{
				xc++;
			}
		}
		int fx=0,cnt=0;
		if(max(xa,max(xb,xc))==xa)fx=1;
		else if(max(xa,max(xb,xc))==xb)fx=2;
		else fx=3;//这里算出了最大的那一个，其他随便安排即可
		for(int i=1;i<=n;i++)
		{
			int maxn=max(a[i],max(b[i],c[i])),cmax=a[i]+b[i]+c[i]-maxn-min(a[i],min(b[i],c[i]));
			if(fx==1 and maxn==a[i] or fx==2 and maxn==b[i] or fx==3 and maxn==c[i])
			{
				qz[++cnt]=maxn-cmax;
			}
		}
		sort(qz+1,qz+cnt+1);
		int ans=0;
		for(int i=1;i<=n;i++)ans+=max(a[i],max(b[i],c[i]));
		for(int i=1;i<=cnt-n/2;i++)ans-=qz[i];
		printf("%d\n",ans);
	}
	return 0;
}
/*
这里使用反悔贪心，尽量分配到喜欢的部门，实在不行，考虑是从喜欢的部门里面挤出来一个人或者自己到第二喜欢的部门，可以证明，分到最讨厌的部门一定不更优，并且这两个部门可以
承载所有员工
那么已经有了分到最讨厌部门不更优的结论，就可以直接暴算了，把最爱人数更少的那些部门可以全额录取员工，而更多的那一个则录取差值更大的那些员工，其他的分配到剩下两个部门，
很明显不会更劣
如果喜好度相等，我给他随便安排一个部门是不会有问题的
读入有点多，尽量快读
*/
/*
1
10
1 0 1
0 3 0
2 0 2
5 5 0
8 8 0
6 6 0
5 5 0
4 4 0
4 4 0
2 2 0
6 6 0

*/