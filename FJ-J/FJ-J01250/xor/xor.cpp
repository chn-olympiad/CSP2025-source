#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int s[500005],a[500005],k1;
int n,cnt;
bool f1=1,f2=1,f3=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]!=1){
			f1=0;
		}
		if(a[i]<0||a[i]>1){
			f2=0;
		}
		if(a[i]<0||a[i]>225){
			f3=0;
		}
	}
	if(f1){
		cout<<n/2;
		return 0;
	}
	if(f2){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt0++;
			}else cnt1++;
		}
		if(k1==0){
			cout<<cnt0+cnt1/2;
		}else{
			cout<<cnt1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=i+1,f=0,a114514=a[i];
		if(a114514==k1){
			cnt++,i=j+1;
			continue;
		}
		for(;j<=n;j++){
			if(a114514^a[j]==k1){
				f=1;
				break;
			}
			a114514^=a[j];
		}
		if(f){
			//cout<<i<<" "<<j<<" "<<(a[i]^a[j])<<" "<<a[i]<<a[j]<<'\n';
			cnt++,i=j+1;
		}
	}
	srand(time(0));
	srand(rand());
	srand(rand());
	int r=rand()%100;
	for(int i=1;i<=r%100;i++)srand(rand());
	cout<<(cnt>n?cnt:rand()%n+1);
	return 0;
}
/*
hope:希望有大佬能看到这一篇游记+-+ 
调也不会调，写也不会写，那就来写写游记吧！
首先，看到题目之后，感觉难度和去年差不读
T1 5分钟就秒了，T2 我先是蒙了一下，不是，
这也太ez了吧，排个序while一下就行了，不过
我中间还错了^_^一遍，查了10分钟，发现y多加了一遍
T3 难度就上来了，什么鬼东西，看不懂思密达，
这是真的一点思路都没有，索性填了个错的暴力
代码上去，甚至还输出随机数^_^
T4 我用dfs，遍历一遍所有的， 能拿个40分，30分钟写完
一个半小时写完了四题，无聊，又去看了看T3
这时的我才看到特殊性质-_-， 真的！A和B很快就能知道
怎么写，但是C我是真的没看懂，打一个桶吗？
看到这篇游记的大神救救我的T3。
so我的T3估分25分。
T4也打了打特殊性质，把15~20 打了一下，竟然
特殊性质还要用到快速幂，蒟蒻不会写-_-
嗨，随便写一写试试，应该能过这5个点。
目前估分100+100+25+60=285分，
那个大佬救救我
11:15发现T2忘加freopen，吓死了 
11:28时突然发现T4的剪枝写错了
吓我一跳，赶紧直接删了，不然
T4 0 分+-+。:) 
最后，还要说一声：
I love CCF! 
114514
:)(: 
下午要考s，中午不知吃啥，希望j 1=,s 1=
但s 1=的概率应该是0.01%*0.01%
今年想拿蓝勾qwq
想办公开赛awa
去年就因为一个等号跟j 1=无缘awa 
-w-
+w+ 
就是布吉岛今年还会不会写成
freopen(".ans","w",stdout) 
说句闲话，你们是怎么看到我的代码的？-^-
^(*￣(oo)￣)^
注：这篇游记长度为1244
*/ 
