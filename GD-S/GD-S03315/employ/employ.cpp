/*
呐呐 我是一名高三的选手 今年是我的最后一次CSP了

今年的题相当简单 预想之中和T4大战三个小时的情况并没有出现

所以有时间写点关于CSP的邮寄啊感叹啊啥的。显然我没有学过语文，看到的同学凑合着看吧。 

很久以前 大概是初一初二的时候吧。当时感觉CSP还是很有一种 新奇的感觉

不知道这样形容是否准确 但是 可能 欣赏比赛最好的时候 就是自己还很萌萌的时候

这样就没法对比赛全力以赴。这样就会关注比赛之外的事情。

每年的CSP前后天气都会变得很凉快。不过，随着全球性的气候变化，这样的经验也不会是永恒的。 

我还能回想起初一或初二的时候走出考场时候的，令人披上外套的寒风，还有暗蓝色的傍晚。以及回味着考场上的苦涩心情的情绪。

初一的时候遇到了儒略历，对战四个小时，只拿到了一个很低的分数。初二的时候遇到了一些奇怪的题（好像是括号啥的，是吗？），我当时很不擅长这些（一直在做数据结构），又拿到了很低的分数。

但即便是这样，似乎出了考场也没有很难过，这样的苦涩只不过像是喝了一杯黑咖啡一样。咔菲好喝！

会感觉自己身处于一大群人之中。好像每个参赛者都很牛，那个时候也有很多同学还在打OI。

这样对于作为竞赛的信息学奥林匹克来说是很坏的。到了高一我仍然有这样的想法，觉得还有一年阿 没必要那么紧张吧（而且我高一的时候觉得自己可牛逼了，肯定能进省队）。这也导致我的高一赛季是完全失败的。

作为一个以集训队为目标的选手 你必然要脱离这种感觉 你必然要鹤立鸡群于芸芸众生

这样的道理，大概几乎每个OIer都知道吧，可能除了当时的我。

（刚刚检查了一下发现 road 的大样例居然没有给满……补了一下不带k的。

初三的时候在本校考试。当时写了个随机化过掉了T1（内心OS：这个T1这么变态吗……），用暴力枚举的写法过了T2，T3 T4写暴力拿到了336分。

出考场问了一下 发现一个当时高一的 Ag 学长是 360.然后发现好像省内初三几乎没有人比我高。

感觉自己很牛逼阿！NOIP 冲刺！能不能进个E队！

结果是 NOIP 获得了，高达整整，100 分！！！不出意料，省选也败选了。

这样初中生活就结束了。高中说实话没那么想写，因为在新奇感褪去，实感或掌控感取而代之的时候，那种让人以文字记录下来再次体味的冲动就消失了。

如果今年NOIP的题很简单的话没准会写一下吧。加纳。 
*/
#include<bits/stdc++.h>
#define ______ namespace
#define _______ std
using ______ _______;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const int mxn=505;
const int mod=998244353;
inline void getmod(int &x)
{
	x-=(x>=mod)*mod; 
}
using ll=long long;
inline void ad(int &x,ll y)
{
	x=(x+y)%mod;
}
char s[mxn];
int dp[2][mxn][mxn];
int cnt[mxn],pre[mxn],fac[mxn];
int c[mxn][mxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read(),i,j,k,l;
	fac[0]=1;
	for(i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		cnt[read()]++;
	pre[0]=cnt[0];
	for(i=1;i<=n;i++)
		pre[i]=pre[i-1]+cnt[i];
	c[0][0]=1;
	for(i=1;i<=n;i++)
		for(j=c[i][0]=1;j<=i;j++)
			getmod(c[i][j]=c[i-1][j]+c[i-1][j-1]);
	dp[0][0][0]=1;
	for(i=1;i<=n;i++)
	{
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(j=0;j<=n;j++)
			for(k=0;k<=n;k++)
				if(int v=dp[i-1&1][j][k])
				{
					int tp=1ll*v*(pre[j]-(i-1-k))%mod;
					if(tp)
						for(l=0;l<=cnt[j+1]&&l<=k;l++)	
							ad(dp[i&1][j+1][k-l],1ll*tp*c[cnt[j+1]][l]%mod*fac[l]%mod*c[k][l]);
					if(s[i]=='1')
						getmod(dp[i&1][j][k+1]+=v);
					else
					{
						for(l=0;l<=cnt[j+1]&&l<=k+1;l++)
							ad(dp[i&1][j+1][k+1-l],1ll*v*c[cnt[j+1]][l]%mod*fac[l]%mod*c[k+1][l]);
					}
				}
	}
	int ans=0;
	for(i=0;i<=n-m;i++)
		for(j=0;j<=n;j++)
			if(j==pre[n]-pre[i])
				ad(ans,1ll*dp[n&1][i][j]*fac[j]);
	cout<<ans;
}
/*
3 2
101
1 1 2

2 0
00
1 1
*/
