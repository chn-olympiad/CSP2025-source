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
int x[1050000],a[500005],dd[500005],f[500005];//这里记录的是当前后缀异或等于a的最小下标x，为0不代表0能，而是根本没有
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	read(n);
	read(k);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	int yhz=0;//当前所有数的异或和
	x[0]=n+1;//一个值都没有
	for(int i=n;i>=1;i--)
	{
		yhz^=a[i];//现在更新
		//printf("%d->%d异或和为%d，现在想要的值是%d，去掉后就能刚好异或得到%d，x[%d]=%d\n",i,n,yhz,yhz^k,k,yhz^k,x[yhz^k]);
		if(x[yhz^k])//有一个值可以异或到
		{
			dd[i]=x[yhz^k]-1;//现在最大的问题就是不知道如何取到异或0，因为最后一个后面没有值，所以异或一定是0
		}
		x[yhz]=i;
	}
	for(int i=1;i<=n;i++)//枚举一下，做DP
	{
		f[i+1]=max(f[i+1],f[i]);
		//printf("f[%d](%d)更新f[%d]:不变，更新f[%d]:+1\n",i,f[i],i+1,dd[i]+1);
		f[dd[i]+1]=max(f[dd[i]+1],f[i]+1);//这里选了这个区间之后，就应该决策后面一个
	}
	printf("%d",f[n+1]);//定义是正在决策的点，不是已经决策过了
	return 0;
}
/*
本题对于每一个点a，求一个后缀异或，然后想找最前面的一个后缀异或能满足异或和等于k，那么把数按照大位为[x..n]异或总和，小位为x本身，压位成一个long long，然后用multiset查询
{a^k,0}，如果能找到值x，那么说明a到x-1可以满足这个要求，并且最为接近，当然不能分成空的一段，所以查询完后再加入集合
加入insert
删除(用不到)erase
lower_bound(x)可以查询序列中大于等于x的第一个的指针
然而我并不会用
那么怎么查询相等的值是否存在？
我是史吗？直接记一下[y..n]异或值为x的最靠前的y不就行了？
*/
/*
4 3
2 1 0 3

*/