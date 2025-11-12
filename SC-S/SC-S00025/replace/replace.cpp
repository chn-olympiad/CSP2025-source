#include<bits/stdc++.h>
using namespace std;
void read(string &n)
{
	n="";
	char c=getchar();
	while('a'>c or c>'z')c=getchar();
	while('a'<=c and c<='z')
	{
		n+=c;
		c=getchar();
	}
}
const int N=2e5+5;
string a[N],b[N];
int x[N],h[N],xx[N],hh[N];//前后A的数量，要替换成功，首先要A不能多，其次，差值还要刚好，这个差值用vector记录一下，然后满足要求的左边a个数和右边的个数用
vector<int> v[10000005];//向后移动多少步
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		read(b[i]);
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<a[i].size();j++)
//		{
//			if(a[i][j]=='b')
//			{
//				x[i]=j;
//				h[i]=a[i].size()-j-1;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<b[i].size();j++)
//		{
//			if(b[i][j]=='b')
//			{
//				xx[i]=j;
//				hh[i]=b[i].size()-j-1;
//				v[xx[i]-x[i]+5000000].push_back(i);
//			}
//		}
//	}
	while(q--)
	{
		string x,y;
		read(x);
		read(y);
		if(n<=100 and q<=100)//小数据，KMP不知道怎么优化，所以不优化了，痛失15分
		{
			int ans=0;
			for(int i=1;i<=n;i++)//枚举每一个替换的串
			{
				for(int j=0;j<=int(x.size())-int(a[i].size());j++)//枚举从哪里开始替换
				{
					if(x.substr(j,a[i].size())!=a[i])continue;
					//printf("现在用第%d个串从%d开始替换,n=%d：从%d开始substr，长度为%d,上限为%d!!!!\n",i,j,n,j+a[i].size(),x.size()-a[i].size()-j,x.size()-a[i].size());
					//cout<<x.substr(0,j)<<"+"<<b[i]<<"+"<<x.substr(j+a[i].size(),x.size()-a[i].size()-j)<<endl;
					//cout<<x.substr(j,a[i].size())+b[i]+x.substr(j+a[i].size(),x.size()-a[i].size()-j)<<"≠"<<y<<endl;
					if(x.substr(0,j)+b[i]+x.substr(j+a[i].size(),x.size()-a[i].size()-j)==y)
					{
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
//		else//我以为他是特性B
//		{
//			int qm,hm,qq,zh;
//			for(int j=0;j<x.size();j++)
//			{
//				if(x[j]=='b')
//				{
//					qm=j;
//					hm=x.size()-j-1;
//				}
//			}
//			for(int j=0;j<y.size();j++)
//			{
//				if(y[j]=='b')
//				{
//					qq=j;
//					zh=y.size()-j-1;
//				}
//			}
//			int ans=0;
//			for(int j=0;j<v[qq-qm+5000000].size();j++)
//			{
//				if(x[v[qq-qm+5000000][j]]>qm or xx[v[qq-qm+5000000][j]]>qq or h[v[qq-qm+5000000][j]]>hm or hh[v[qq-qm+5000000][j]]>zh)
//				{
//					ans++;
//				}
//			}
//			printf("%d",&ans);
//		}
	}
	return 0;
}
//题意难理解，但是稍作观察就能发现其实是只能替换一次，并且可以在任意位置进行一次替换
//食用KMP算法匹配就能把每次查询降到L1L2
//然而匹配之后的判等我不会
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/