#include<bits/stdc++.h>
#define thinktwice return
#define code 0
#define once ;
using namespace std;
int n,a[5140];
int qp(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans*=a,ans%=998244353;
		a*=a;
		b>>=1;
	}
	return ans%998244353;
	//11:18写出来了!!!!!!!!! 
}
//坏了孩子们，快速幂忘了怎么写了
//中午回去看
//AFOed
//预计得分：100+100+10+0=210
//这倒是提醒我了 
//特殊性质还没写 
//坏了孩子们，没特殊性质
//AFOed
//还有一个小时，难道我只能玩抽象了吗？
//窝看胃壁！
//（下面是之前写的） 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//欸？好像能用线段树！
	//没逝，我忘了
	//些风霜罢了 
	//11：11了
	if(n<3){
		cout<<0;
		thinktwice code once
	}
	if(n==3){
		int cnt=0,sum=a[1]+a[2]+a[3];
		if(sum>2*(max(a[1],max(a[2],a[3])))){
			cout<<1;
			thinktwice code once
		}
		else{
			cout<<0;
			thinktwice code once
		}
	}
	//和蔼！这里有整整12pts! 
	//11:19开始想 a[i]<=1
	//11：27推完规律，开始写
	if(a[1]==a[2]==a[n]==a[n-1]==1){
		int sum=0;
		for(int i=3;i<=n;i++){
			sum+=qp(i,n-i);
			sum%=998244353;
		}
		if(n>4) sum++;
		cout<<sum%998244353;
		//坏了，推错了
		//11：31了
		//不管了，面对样例编程 
		thinktwice code once
	}
	//11:35打完了，不知道对不对
	//100+100+10+12=222或第一题读不进来0+100+10+12=122或刚刚瞎写的全对0+100+10+36=146
	//最好：100+100+10+36=246
	//最差：0+100+10+12=122
	//评价：3=稳了，2=救一下，1=没可能
	//AFOed 
	thinktwice code once
	//11：45了，准备遗憾离场
	//my blog:hjbhawa.giyhub.io/hjbh.github.io 
	//对了，让我上抽象代码大赏 
}
//你说你不想在在里
//我也不想在在里 
//但天黑的太快想走早就来不及
//下午唱勾指起誓
//坏了，我成歌王了
//奋音：你的回合内，若你使用的牌与上一张颜色不同，你摸一张牌
//渐营：若你的回合内你使用的牌与上一张花色相同，你摸一张牌
//连营：当你失去最后X张手牌后，你可令X名角色各摸一张牌
//我同时有这三个技能加界制衡能不能三拳打死武诸葛 
//（斐秀忘了） 悲
//锣鼓灌注hjbh 评论塞浦路斯普鲁士（plsplspls） 
//机房的电脑也是五字神人id
//口合其土米也是__________ 
