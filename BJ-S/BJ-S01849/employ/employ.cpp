#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pub push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=0;
const ll mod=998244353;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
const ll inf=0x3f3f3f3f3f3f3f3f;

int n,m,C[505][505];
int a[505],cnt[505],s[505];
ll f[505][505],g[505][505],fc[505],ifc[505];

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	cin>>n>>m;
	C[0][0]=1;
	fc[0]=1;
	for(int i=1;i<=n;i++){
		fc[i]=fc[i-1]*i%mod;
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	ifc[n]=qpow(fc[n],mod-2);
	for(int i=n;i;i--)ifc[i-1]=ifc[i]*i%mod;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c=='1';
	}
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		++cnt[c];
	}
	s[0]=cnt[0];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+cnt[i];
	g[0][0]=1;
	for(int i=0;i<n;i++){
		memcpy(f,g,sizeof(g)),Cl(g);
		for(int j=0;j<=i&&j<=n-m;j++)for(int k=0;k<=i;k++)if(f[j][k]){
			if(a[i+1]){
				(g[j][k+1]+=f[j][k])%=mod;
				for(int x=0;x<=k&&x<=cnt[j+1];x++){
					(g[j+1][k-x]+=f[j][k]*C[k][x]%mod*
					C[cnt[j+1]][x]%mod*fc[x]%mod*(s[j]-i+k)%mod)%=mod;
				}
			}else{
				for(int x=0;x<=k&&x<=cnt[j+1];x++){
					(g[j+1][k-x]+=f[j][k]*C[k][x]%mod*
					C[cnt[j+1]][x]%mod*fc[x]%mod*(s[j]-i+k)%mod)%=mod;
					(g[j+1][k-x]+=f[j][k]*C[k][x]%mod*
					C[cnt[j+1]][x+1]%mod*fc[x+1]%mod)%=mod;
					(g[j+1][k-x+1]+=f[j][k]*C[k][x]%mod*
					C[cnt[j+1]][x]%mod*fc[x]%mod)%=mod;
				}
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=n-m;j++){
		int k=0;
		for(int x=j+1;x<=n;x++)k+=cnt[x];
		ll coef=fc[k];
		(ans+=coef*g[j][k])%=mod;
		// cerr<<j<<" "<<k<<": "<<coef<<" "<<f[n][j][k]<<"\n";
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	__INIT__();
	int T=0;DC?cin>>T,1:T=1;
	for(int c=1;c<=T;c++)__SOLVE__();
	return 0;
}
/*
游记

写完题没事干了，不敢对拍，这个机子感觉一拍就死了

刚入场看到虚拟机+2cpu+3.8G 内存就笑嘻了，感觉 vsc 和 firefox 同时开就炸了，所以一直在轮流切换

开始之后把四个题都读一遍

T1 好像是直接用 pq 记录一下

T2 只保留原图 mst 上的边之后直接 2^k*k*n 就行

T3 好像是哈希一下然后两个 trie 上都要是祖先关系于是转二维偏序

T4 看起来是可以做的

T1 对的原因其实主要是 n 是偶数，于是如果有一个超的就直接把它里面能变化的全都调开，剩下的位置一定都合法

T2 就是因为如果在原图里就不会加入这条边说明肯定没用，这样只有 O(n) 条边，于是直接枚举使用的乡镇集合

T3 直接把所有不同位置的 min 和 max 整个区间求出来，于是把串划分为 A,B1,B2,C 几部分，那么两对串有贡献当且仅当 B1=B1,B2=B2，A 和 C 分别是后缀和前缀，于是对中间哈希之后往两边各开一个 Trie，确定出祖先关系之后跑二维偏序就是对的

T4 最开始把题读成前面有 ci 个被拒绝的人他就放弃了，然后心想这不是随便容斥都是平方的吗，写完发现样例 2 死活过不去，才发现读错题了

于是重新思考了一下对的题意，发现题目可以转化为确定 c 之后 i 从 1 扫到 n，中间维护一个变量 cur，如果 si=0 或者 ci<=cur 那么 cur+1，问有多少种方式使得 cur<=n-m

显然这个东西只能按照顺序从前往后 dp，每次填写 <=cur 或 >cur 的数，但是 cur 变化的时候 >cur 的数不好处理，于是使用 CF1842G 的套路（服了马大预言家），在 cur 变化的时候再考虑前面放了几个 cur

那所以直接记 f[i][j][k] 表示前 i 项，目前 cur=j，ci>cur 的用了 k 个的排列数量，转移的时候分讨 si，在 cur 增加的时候枚举前面使用多少个 cur+1，注意 si=0 且放一个 cur+1 的时候系数不太一样

看起来是四次方的，但是你仔细想一下发现 x 的枚举范围是 cnt[j+1]，那所以所有 j 加起来 x 的枚举范围其实是 O(n) 的，于是就 O(n^3) 做完了

还有 1h 结束，what should i do
*/