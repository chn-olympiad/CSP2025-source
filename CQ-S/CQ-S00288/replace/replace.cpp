/*
replace
首先找出 LCP 和 LCS，这样确定中间一大段都必须被替换。
甚至不给 $\sqrt{L}$ 活路，怎么这场分数给得这么极端。
感受上你要读入，每组数据明明能够线性做的。
那么枚举一个前缀，找到后面一串能够匹配的东西来做替换。
我其实有个想法是跑 AC 自动机。
如果你同时在两个 AC 自动机上面跑到一个可替换对的结尾，那么这两个就可以进行替换。
替换之后合法的充分条件是它们覆盖了有差异的整个区间，这是容易判断的。
我感觉挺对的说。
一眼找不出错，要写吗？不懂。
我觉得很对，那么难点就是我需要重新发明一下 AC 自动机。
好像也没完，AC 自动机匹配上了还要看 fail 树上那堆父亲有多少是合法的，暴力跳是不是不太能对。
考虑到这题估计就是 AC 自动机怎么怎么做，我也搞不出来，就打暴力嘛。
发现平方暴力拼 B 性质暴力已经 50pts 了，可以的。

B 性质要敲一个二维偏序，烦人，先挂着。
*/
#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
constexpr int N=200010,LEN=5000010,P=131;
int n,q;
string s[N][2],t[N][2];
ull hs[N][2],h[2][LEN],Pw[LEN];
namespace BF
{
	inline int solve()
	{
		for(int i=1;i<=n;i++)for(int d=0;d<=1;d++)for(int j=0;j<s[i][d].length();j++)hs[i][d]=hs[i][d]*P+s[i][d][j];
		for(int i=1;i<=q;i++)
		{
			cin>>t[i][0]>>t[i][1];
			if(t[i][0].length()!=t[i][1].length())
			{
				cout<<0<<endl;
				continue;
			}
			int len=t[i][0].length(),ans=0;
			for(int j=0;j<len;j++)
			{
				h[0][j+1]=h[0][j]*P+t[i][0][j];
				h[1][j+1]=h[1][j]*P+t[i][1][j];
			}
			for(int j=0;j<=len;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(j+s[k][0].length()>len)continue;
					int lens=s[k][0].length();
					if(h[0][j+s[k][0].length()]-h[0][j]*Pw[s[k][0].length()]==hs[k][0]&&h[0][len]-(h[0][j+lens]-h[0][j]*Pw[lens])*Pw[len-(j+lens)]+hs[k][1]*Pw[len-(j+lens)]==h[1][len])ans++;
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Pw[0]=1;
	for(int i=1;i<LEN;i++)Pw[i]=Pw[i-1]*P;
	cin>>n>>q;
	int L=0;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1],L+=s[i][0].length()+s[i][1].length();
	if(L<=2000)return BF::solve();
	return 0;
}