#include<bits/stdc++.h>
using namespace std;

const int N=5005,MX=5001,mod=998244353;
int a[N],n;
long long dp[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+1;j<=MX;++j) ans=(ans+dp[j])%mod;
		for(int j=MX;~j;--j) dp[min(j+a[i],MX)]=(dp[min(j+a[i],MX)]+dp[j])%mod;
	}
	cout<<ans;
	return 0;
}
/*
今年j组好简单，虽然我去年就AK了，哈哈哈 

不知到会不会选到GD抽象代码中，不过既然如此，我就要开始钓鱼了，桀桀桀

//freopen("polygon.out ","r",stdout); 
//freopen(" polygon.in",'w',stdin);

真服了，10点才能交卷，但我9:05就AK了啊啊啊啊啊，明年我不要考J

今年难度评估红 红 黄 黄

为什么去年那么难啊啊啊啊啊

不过我AK了哈哈哈哈哈
希望下午S组能350加油！！！！！！！！！！！！！
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++

我还以为T4跟去年一样是高质量蓝题呢wuwuwu

我常常追忆过去，后面不会了emm...

今年j题面好评！！！！！！！！！！！！！！！！！！！！！！！

今年j题面我的评价：简洁明了，通俗易懂！！！！！！！！！！！

wuwuwu从9:00熬到10:00告诉我不能离场这不搞心态吗啊啊啊啊啊啊

我要出去看b站，玩游戏呜呜呜

算了，既来之着安之，我只能写扫雷玩了呀桀桀桀

写到一半不想玩了，剩下的时间干啥啊！！！！！！！！！！！！

今年j题面为什么这么容易读懂呜呜呜，不应该复杂一点让我用更多时间吗

瑶瑶党万岁！！！！！！！！！！！！！！！！！！！！！！！！（其实六大女主都爱看，别问为什么是六大，但我也希望路人能强势一些qwq 

大家好，我是桌桌子emm...

额，我不知道写啥了

我决定了，我要给T4写题解，让我的rp++

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

突然发现我不会用Mackdown(我又没有写错名字啊 

我写了这么久一定要把我加进去啊！！！！！！！！！！！！！！

算了看我T3代码吧，我不想在T4写了qwq__ 
*/
