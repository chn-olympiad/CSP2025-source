#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[1000001],f[5005][5005],g[5005];
int qpow(int x,int y){
	if(y==0)return 1;
	int ans=qpow(x,y/2);
	ans=ans*ans%mod;
	if(y&1)ans=ans*x%mod;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5000;j++){
			if(j>=a[i])f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%mod;
			else f[i][j]=f[i-1][j];
		}
	}
	int ans=(qpow(2,n)-1+mod)%mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans-=f[n][j];
			ans%=mod; 
			ans=(ans+mod)%mod;
		}
	}
	for(int i=1;i<=n;i++){
		g[a[i]]++;
		if(g[a[i]]!=1)ans=(ans+(g[a[i]]-1)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
T4上难度了吗，这么有操作

目前会40pts的暴力，再想一下
不是推式子怎么推到多项式状物了，有点难受。

等一下，不会真是生成函数吧，太抽象了，不可战胜啊。

不对，生成函数怎么去重。

想一些正经做法

不好，是猫树分治优化dp，但是没有猫树（

那我会了 

不是怎么还是有多项式，不想玩了。

我考的是入门组吧，怎么这么神秘，还是有我不会的性质啊。

马萨卡，难道这样是对的吗？ 

好像背包是对的，可以处理去重 


欸等等我现在AK了（并不一定），后面两个小时不是只能睡觉了

哦，还可以冲浪。

怎么冲浪被ban了，受不了了。 
 
//freopen("polygon.in","r",stdin); 
//freopen("polygon.out","w",stdout);  
#include<bits\stdc++.h>
#include<bits./stdc++.h>
#include<bits.\stdc++.h>

你应当是被骗进来的。

我们可以注意到这场比赛我初一时来都几乎可以AK（这么说或许有点马后炮的意思，况且我可能还会挂inf分）

而且阴间的点可能只有T2的水样例，其他都不算难。

这么算下来上午考了两道dp，下午是不是数据结构场啊。

说是分块单推人，结果一道分块都没写似乎不太好 

不管了，洛谷@jerry1717，欢迎大家壶关喵 
*/