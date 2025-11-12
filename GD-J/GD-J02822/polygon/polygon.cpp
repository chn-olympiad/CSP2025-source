#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define mod 998244353
int n,a[5555],f[5555][4];
long long ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=ans*2%mod;
	}
	ans=(ans-n-1+mod)%mod;
	ans=(ans-n*(n-1)/2+mod)%mod;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
			ans=(ans-f[j][2]+mod)%mod;
		for(int j=a[n];j>=a[i];j--){
			if(j==a[i]) f[j][1]++;
			f[j][2]=(1ll*f[j][2]+f[j-a[i]][1])%mod;
			f[j][2]=(1ll*f[j][2]+f[j-a[i]][2])%mod;
		}
	} 
	cout<<ans;
	return 0;
}
/*
数数题
直接算有多少满足条件的方案不太好算
考虑正难则反，用总方案数减去不满足的方案数即可
总方案数显而易见是2^n
不满足的方案数：
1.选的不足3个，这个可以直接算
选0个：1种；选1个：n种；选2个：n*(n-1)/2种
2.选出来的构不成多边形，dp来算
不满足的条件是 所有选出来的木棍长度之和< 2*所有选出来的木柜的最大值 
这个的方案数并不是很好算，可以将其变形 
两边同时减去 最大值 变成除最大值外的总长度小于最大值
那我们可以 dp 算出小于最大值的总长度的方案数
但是要求至少要用两根棍子，不然即使加上最大的那根也不足三根 
于是再开一维：1表示用了1根，2表示用了>1根即可
至于如何算出方案数，直接背包DP。 
然后对于每一个a_i，减掉所有的 f[j][2](j<a_i) 之后就是答案了 
*/
