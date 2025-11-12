#include<bits/stdc++.h>
using namespace std;
void read(int &n)
{
	n=0;
	char c=getchar();
	while(c>'9' or c<'0')c=getchar();
	while(c<='9' and c>='0')
	{
		n=n*10+c-'0';
		c=getchar();
	}
}
const int Q=998244353;
int a[5005][5005],s[5005];//根本就不用滚动，然后求一下正好长度相等的方案数，直接复制粘贴之后转移就行了，长度为5001不代表真的是5001，代表的是答案已经超过了5001，什么具体数值没有意义了
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(s[i]);
	}
	sort(s+1,s+n+1);
	a[0][0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)//只用前i-1根木棍更新i的答案，确保没有重复
	{
		for(int j=s[i]+1;j<=5001;j++)
		{
			//if(j<=15)printf("ans+=a[%d][%d]=%d\n",i-1,j,a[i-1][j]);
			ans=(ans+a[i-1][j])%Q;
		}
		for(int j=0;j<=5001;j++)a[i][j]=a[i-1][j];
		for(int j=0;j<=5001;j++)
		{
			if(j+s[i]>5000)
			{
				a[i][5001]+=a[i-1][j];
				a[i][5001]%=Q;
			}
			else
			{
				//if(j<=10)printf("%d,%d->%d,%d:%d\n",i-1,j,i,j+s[i],a[i-1][j]);
				a[i][j+s[i]]+=a[i-1][j];
				a[i][j+s[i]]%=Q;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
/*
由于小R的小木棍是正数长度，所以不用去除一个点求的时候选自己的方案，因为选了自己只要不是只有自己就一定可以，而只有自己一定不行，乘上一个快速幂就行了
然而限制应该是最大的木棍
那么排序后，从小到大，算一算任意长度的棍子拼起来的方案数就行了，而且因为是计算答案之后再更新自己，并且最大的点数不同，所以不用去重
*/
/*
5
1 2 3 4 5

*/