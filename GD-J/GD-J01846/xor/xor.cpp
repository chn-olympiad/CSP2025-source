//RP++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100,inf=0x3f3f3f3f;
int a[N],s[N],n,k,ans=0,f[N],nxt[N],las[N],fir=1;
inline void dfs(int x){
	int now=x,cnt=1;
	while(now>=1){
		if(f[now]&&f[now]<x)++cnt,x=now;
		--now;
	}
	if(cnt>ans)ans=cnt;
	return;
}
inline void solve(){
	for(int len=0;len<=n;++len)
		for(int l=fir;l<=n-len;l=nxt[l]){
			int r=l+len;
			if((s[r]^s[l-1])==k&&!f[l])f[l]=r,nxt[las[l]]=nxt[l],las[nxt[l]]=las[l];
		}
	for(int i=n;i>=1;--i)
		if(f[i])dfs(i);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;for(int i=1;i<=n;++i){
		cin>>a[i];s[i]=s[i-1]^a[i];nxt[i]=i+1,las[i]=i-1;
	}
	solve();
	cout<<ans;
	return 0;
}
/*
最佳损友-陈奕迅
朋友，我当你一秒朋友
朋友，我当你一世朋友
奇怪，过去再不看回首
怀念，其实时时还有
朋友，你试过将我营救
朋友，你试过把我批斗
无法，再与你交心联手
毕竟难得有过最佳损友
从前和你
促膝把酒倾通宵都不够
我有痛快过
你有没有
很多东西今生只可给你
保守直到永久
别人如何明白透
实实在在踏入过我宇宙
即使相处到有个裂口
命运决定了以后再无法聚头
但说过去却那样厚
问我有没有
确实也没有
一直躲避的借口
非什么大愁
为何旧知己到最后
变不到老友
不知你是我的友
已没法望透
被推着走
跟着生活流
怀念陌生的
是昨日
最亲的某某
生死之交当天不知罕有
到你变节了
只觉未够
多想一天彼此都不追究
相邀再次喝酒
待葡萄成熟透
但是命运入面每个邂逅
一起走到了某个路口
是敌与是友
各自也没有自由
位置变了各有队友
问我有没有
确实也没有
一直躲避的借口
非什么大愁
为何旧知己到最后
变不到老友
不知你是我的友已没法望透 
被推着走
跟着生活流
怀念陌生的
是昨日
最亲的某某
早知解散后各自有
际遇做导游
奇就奇在接受了
各自有路走
却没人像你让我
眼泪背着流
严重似情侣讲分手
有没有
确实也没有
一直躲避的借口
非什么大愁
为何旧知己到最后
变不到老友
不知你是我的友已没法望透 
被推着走
跟着生活流
怀念陌生的
是昨日
最亲的某某
总好于
那日我没有
没有遇过某某
*/ 
