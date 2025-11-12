#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=5e3+10,mod=998244353,S=5001;
ll n,a[N];
ll f[N][4],g[N][4];//当前dp / 前缀和dp
ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod,y>>=1; 
	}
	return res;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	g[0][0]=1;
	ll res=0;
	ll ans=((ksm(2,n)-1-n-n*(n-1)/2)%mod+mod)%mod;
//	write(ans);
//	putchar('\n');
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(S,res+a[i]);j++){
			for(int k=0;k<=3;k++) f[j][k]=0;
		}
		for(int j=0;j<=min(S,res);j++){//如果上一个 
			for(int k=0;k<=3;k++){
				if(j<=a[i]&&k>=2) ans=(ans-g[j][k]+mod)%mod;
				f[min(j+a[i],S)][(k+1>3 ? 3 : k+1)]=(f[min(j+a[i],S)][(k+1>3 ? 3 : k+1)]+g[j][k])%mod;
			}
		}
		res+=a[i];
		for(int j=0;j<=min(S,res);j++){
			for(int k=0;k<=3;k++){
				g[j][k]=(g[j][k]+f[j][k])%mod;
			}
		}
//		for(int j=0;j<=15;j++){
//			for(int k=0;k<=3;k++) write(g[j][k]),putchar(' ');
//			putchar('\n');
//		}
//		putchar('\n');
	}
	write(ans);
	return 0;
}
/*
---------------------
我要上奇葩行为大赏

快来关注Fenki_lo 

我是一只狼王 嗷呜~
----------------------
神秘计数dp题

但这也不好算 

允许n^2

区间？ 

sort之后直接考虑？

设f(i,j) 表示前i根木棒和为 j 的方案数且最大值为i

f(i,j)=sum f(k,j-a[i]) (j>a[i]/2+a[i])

时间复杂度……O(n^4)

显然可以前缀和优化到n^3

设 g(i) 表示到当前位置和为i的方案数

f(i,j)=g(j-a[i]) (j>a[i]/2+a[i]) 

然后呢？

哎？实际上能转移的状态是一个区间，考虑位移

并且排序之后限制是逐步递增的

也就是说废弃的状态是一段递增前缀

从这个入手

也就是说到i时比a[i]/2+a[i]小的状态都是没法转移到的

但是整体维护位移带log 

还有神秘3倍常数

优化不动了 

于是考虑容斥

这样的话变成 j<=a[i]/2

就好算很多哎

卧槽带8倍常数

跑不满，勉强能卡过（2e8） 

赌一把 

发现我们的容斥只关注使用根数和不合法根数奇偶性

于是设 f(i,j,0/1,0/1/2/3) 表示到当前和为j，不合法火柴数为偶数/奇数，共使用0/1/2/>=3根火柴

考虑怎么做。主要是到了2501就不可能不合法了

啊呀好耶 

转移是容易的。

又是一年一度的调题时间

5
1 2 3 4 5

ans:8

expected:9

1 2 3

1 2 3 合法！

操理解错题意了

前面状态怎么样和后面没关系！

这个容斥更加简单！ 

我赞美CCF！ 
*/
