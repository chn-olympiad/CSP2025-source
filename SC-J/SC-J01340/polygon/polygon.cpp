#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
#define ll long long
int n,a[N];
void solve1(){
	ll ans=0;
	for(int i=3;i<=n;i++){
		for(int j=0;j<(1<<(i-1));j++){
			int sum,cnt,tmp=j;sum=cnt=0;
			for(int k=1;tmp;k++,tmp/=2){
				if(tmp&1){
					cnt++;
					sum+=a[k];
				}
			}
			if(cnt<2)continue;
			else if(sum>a[i])ans=(ans+1)%mod;
		}
	}
	cout<<ans%mod;
}
ll qpow(ll a,ll b){
	ll res=1;
	for(;b;b/=2,a=(a*a)%mod)if(b&1)res=(res*a)%mod;
	return res%mod;
}
void solve2(){
	ll ans=qpow(2,n);
	ans=(ans-n-1);
	ans=(ans-(n*(n-1))/2);
	cout<<(ans+mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=20)solve1();
	else if(a[n]==1)solve2();
	return 0;
}
/*
Start Time 2025/11/1 9:56
背景：T1,T2应该是过了，
T3在对拍，应该也没什么大问题，T4写了40pts暴力，准备休息一下，先来写个游记 
7:54 门口遇到了lrf，xhy，还蹭了一会伞。
8:00 可以进考场了
8:05 到了，手机手表关机，失联，发现和czz一个考场 
8:12 看了一遍考生须知，试了一下Linux系统，发现不会编译VScode，索性放弃回来使用Dev-c++
8:30 开始了，但是还没有发题，先写个模版
8:40 T1语法题，扫一遍就行了（然后大样例就卡到了0.9s，是应为打太多数字了吗，n才1e6）
8:54 T2也非常简单，做完了
9:15 T3有思路了，先打了个O(n^2)暴力，60pts
9:30 T3想到优化了，调了 一会，开始对拍了
9:45 T4打了个 40pts暴力
9:56 开始写以上第一部分游记，于
10:05 完成，继续想T4 
10:10 不放心，测一下T1，结果被卡到1.1s了，想了一下，
把scanf，printf换成cin，cout并加上tie，据xhy大佬说
这样要比scanf还快，试了一下，直接干到0.2s了 
10:53 还是没有想出来正解，写了一个max a_i=1的特殊性质，预期再拿24pts

总结：
预期分数：T1 100pts T2 100pts T3 100pts T4 64pts 
*/