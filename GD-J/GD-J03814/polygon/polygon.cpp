/*
Hello 你好  
非常感谢你可以 check 我的代码
由于这次比赛真的太简单了，我开始怀疑我的正确性  
不管这么多了，CCF 是打算让 J1 400，J2 390，J3 380 吗
算了，我们来说做题的心路历程吧：
1.  拿到这道题目“多边形”，我开始幻想一些神奇的计几做法，但在拿到这道题
的一刻，我的心终于放下了，眼看一个连题面都不用读，只读样例都知道干什么的东西
2.   开始做。见题目这么简单，并不着急，我现在 D 盘建好了目录，再在桌面编辑
我们完成输入后，将所有木棍从小到大排，这样就能方便确定最大值了。
我们每次以 a_i 这个数为最大值统计的就是有多少中组成方案使得这些木棍的
长度和大于 a_i。我们充分发扬正难则反精神，统计和小于等于 a_i 的方案数
用一个 01 背包可以实现，那么方案总数就是 2^(i-1)-刚才统计出的背包中
和小于等于 a_i 的方案数。全部加起来取模就是答案了。 
且慢，如果只有两根木棍，那根本不可能组成多边形，怎么判呢？
好耶，发现我们排完序后一定是前面的不大于后面的我们一定能判到，还是太友善了
那么我们在 10 分钟建完文件夹后也是光速写完了。
建议难度：普及/提高- 
建议标签：背包 dp，枚举，排序 
给个 100 分吧。 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=5050;
typedef long long ll;
const ll mod=998244353;
int n;
int a[N];
ll cnt[N];
inline ll qpow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cnt[0]=1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll res=qpow(2,i-1);
		for(int j=0;j<=a[i];j++){
			res=(res-cnt[j]+mod)%mod;
		}
		ans=(ans+res)%mod;
		for(int j=5000;j>=a[i];j--){
			cnt[j]=(cnt[j]+cnt[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
/*

*/ 
