#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n,ans,a[10000],dp[5001][5001];

void dfs(int now,int s,int last,int cnt)
{
	if(now==n+1)
	{
		if(s>2*last&&cnt>=3) ++ans;
		ans%=mod;
		return;
	}
	dfs(now+1,s,last,cnt);
	dfs(now+1,s+a[now],a[now],cnt+1);
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("poltgon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	if(a[n]==1)
	{
		for(int i=1;i<=n;++i) dp[i][1]=i;
		for(int i=1;i<=n;++i) dp[i][i]=1;
		for(int i=1;i<=n;++i) for(int j=2;j<i;++j) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
		for(int i=3;i<=n;++i) ans=(ans+dp[n][i])%mod;
		cout<<ans;
	}
	return 0;
}

/*
不要爆我准考证号，谢谢！！！

md什么玩意儿啊，9:55突然灯关了几秒钟，wc，还以为停电了，差点没被吓死 
T4的dp是什么玩意儿啊，完全不像是我们这些juruo能推出来的，虽然是个二维dp
所以先拿n<=20的那40分呗
现在由拿了max=1的那24分，爽 
再讲讲我推吧 
原神：芙宁娜
绝区零：星见雅
崩铁：花火，遐蝶
崩三：希儿
鸣潮：无，毕竟没怎么玩
然后小说里没有推，但是有认为刻画的比较好的角色（因为主角都很好，所以不写主角了）：
戏神：韩蒙，陆循，简长生+白起（在此骂一下妄灾，它可是敢惹嘲和拽哥的灭世啊） 
龙族：路明泽，楚子航，诺诺，绘梨衣，源稚女&风间琉璃（在此骂一下赫尔佐格，SB，制造刀子） 
十日终焉：陈俊南（在此骂一下青龙，招笑） 
斩神：拽哥，纪念，安卿鱼 （在此骂一下迦蓝，wc刻画的像极了一坨大的，被感情线毁了） 
诸神愚戏：甄欣（在此痛骂作者，好好一本书，世界观多好，非要动不动就提车速，神经） 
sakura最好了（划掉）
人类文明，永不将熄（划掉） 
*/












