#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const int I=1e9;
const ll J=1e18,N=507,P=998244353;
ll qp(ll x,ll y=P-2) { return y?(y&1?x:1)*qp(x*x%P,y>>1)%P:1; }
ll fac[N],fnv[N];
struct init { init() {
	fac[0]=1; for (ll i=1;i<N;i++) fac[i]=fac[i-1]*i%P;
	fnv[N-1]=qp(fac[N-1]); for (ll i=N-1;i;i--) fnv[i-1]=fnv[i]*i%P;
} } A;
ll C(ll x,ll y) { return x<y||x<0||y<0?0:fac[x]*fnv[x-y]%P*fnv[y]%P; }
ll n,m,c[N],sum[N],ans;
ll nm,w[N];
ll ccc[1048576];
char s[N];
namespace solve1 {
	ll d[17],res[17];
	void mian() {
		iota(d+1,d+n+1,1);
		do {
			ll zl=0,mz=0;
			ll ss=0,cnt=0;
			for (ll i=1;i<=n;i++) {
				if (s[i]=='0') zl++;
				else {
					if (zl<c[d[i]]) mz++,ss|=1ll<<cnt;
					else zl++;
					cnt++;
				}
			}
//			ccc[ss]++;
//			printf(" %lld\n",ss);
			res[mz]++;
		} while (next_permutation(d+1,d+n+1));
		ll ans=0;
		for (ll i=m;i<=n;i++) (ans+=res[i])%=P;
		cout<<ans<<"\n";
	}
}
namespace solve2 {
	const ll N=19;
	ll dp[1ll<<N][N],ans;
	void mian() {
		dp[(1ll<<n)-1][0]=1;
		for (ll s=(1ll<<n)-1;s;s--) {
			ll p=n-__builtin_popcount(s)+1;
			for (ll i=0;i<=n;i++) if (dp[s][i]) {
				for (ll j=0;j<n;j++) if (s>>j&1) {
					(dp[s^1ll<<j][i+(::s[p]=='0'||c[j+1]<=i)]+=dp[s][i])%=P;
				}
			}
		}
		for (ll i=0;i<=n-m;i++) (ans+=dp[0][i])%=P;
		cout<<ans;
	}
}
ll mxx(ll x) { return max(x,0ll); }
namespace solve3 {
	void mian() {
		ll ans=1;
		for (ll i=1;i<=nm;i++) {
			(ans*=mxx(sum[w[i]+i-1]-(i-1)))%=P;
		}
		(ans*=fac[n-nm])%=P;
		cout<<(fac[n]+P-ans)%P;
	}
}
namespace solve4 {
	void mian() {
		if (nm<n) cout<<"0";
		else if (sum[0]) cout<<"0";
		else cout<<fac[n];
	}
}
void mian() {
	scanf("%lld%lld%s",&n,&m,s+1);
	for (ll i=1;i<=n;i++) if (s[i]=='1') nm++,w[nm]=i-nm;
	if (nm==0) return cout<<"0\n",void();
	for (ll i=1;i<=n;i++) scanf("%lld",&c[i]),sum[c[i]]++;
	for (ll i=1;i<=n;i++) sum[i]+=sum[i-1];
//	if (n<=10) return solve1::mian();
	if (n<=18) return solve2::mian();
	if (m==1) return solve3::mian();
	if (m==n) return solve4::mian();
	for (ll s=0;s<1ll<<nm;s++) if (__builtin_popcount(s)>=m) {
		ll res=0;
		for (ll t=s;;t=(t-1)&s) {
			ll mz=0,zl=0,rw=1;
			for (ll i=1;i<=nm;i++) {
				if (s>>i-1&1^1) {
					(rw*=mxx(sum[w[i]+zl]-zl))%=P,zl++;
				}
				else {
					if (t>>i-1&1) {
						(rw*=mxx(sum[w[i]+zl]-zl))%=P,zl++;
					}
					else {
						mz++;
					}
				}
			}
//			printf(" %lld %lld %lld %lld\n",s,t,rw,fac[mz+n-nm]);
			(res+=(__builtin_popcount(t)&1?P-rw:rw)*fac[mz+n-nm])%=P;
			if (!t) break; 
		}
//		printf("%lld %lld %lld\n",s,ccc[s],res);
		(ans+=res)%=P;
	}
	cout<<ans;
}
bool ORY; int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	while (1)
//	int t; for (scanf("%d",&t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
计数题！
每个人会在它前面出现了至少 c_i 个人取到 0 或者走了的情况下走掉
n<=500。问多少排列能 >=m 个人被录 
感觉像那种会在模拟赛里被放 t2 的东西

相当于选出若干个人放在 1 的位置
如果前面走了 c_{p_i} - w_i 个人，p_i 会走

最难处理的点在于，一个人走不走可能取决于前面的人走不走
是个不太好拆开的限制

感觉是那种考察贡献延迟计算的东西。 

按特殊性质想吧

#1~5 ok 20

# A 没有 0
全想错了。还好发现了。 
如果一个人前面走了 c_{p_i} 个人，他也会走
我们贪心在 c_{p_i} 中取 0,<=1,<=2,... 的序列  
考虑（或者说必须）按值域做
考虑现在插入了 <=i 的数。然后是什么情况

能不能对所有走人的方案计算它被取到了多少次

枚举走了多少个人。
对于 c=x 且走了的人，它们的要求是必须分布在走的人的一个长为 k-i+1 状物的后缀
对于没走的人，它们的要求是必须不分布在这个后缀
方案数好像是可以单次 O(n^2) DP 计算的？

ok 20？ 

有没有什么可推广性。想一下。
说实话不好推广。

感觉应该开始考虑拼好分了。时间有限。 

# m=1
全部走了？
那限制全部是 c_{p_i}<=x。这个我会。
ok 12 

# m=n ok 4

# B 1 的个数很少
直接枚举走的是谁，然后算一些方案数
形如某种 c_{p_i} <= lim 或 > lim 

可以和暴力一起写

有一个新的思路。
去对于一个走人的情况，计算多少种方案取到的这种情况
对于没走的位，要求 c_i>=某值
对于走了的位，要求 c_i<=某值
这个“某值”呈不降状态 
agc036f 有类似的问题，但是那题的容斥思路没有办法往这上面套。
诶，真没办法吗
我们容斥哪些 c_i>=某值 的限制没有符合
那所有的限制都是 c_i<=某值的形式了，或者有些根本没有限制！

把式子写出来。

好像不必写得太清楚。反正就是：
+ 如果我们指定这一位没走：
	+ 如果容斥到了这位，那么形如 c_i<=这位限制，*(-1)
	+ 如果没容斥到这位……等会再说 
+ 如果指定这一位走了：
	+ 形如 c_i<=这位限制

由于限制单调不减，可以类似 prod(a_i-i+1) 的形式处理

dp_{i,j,k} 前 i 个 1 被确定，指定了 j 位没走，容斥了 k 位没走
然后考虑没限制的是什么。
哦。随便排。 
复杂度等于状态数。
哇！！！！！ 

先写暴力容斥验证。如果假掉了直接去拼好分。 
*/
