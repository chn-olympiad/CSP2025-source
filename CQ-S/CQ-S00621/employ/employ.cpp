/*
出发！前进！ 
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
/*
cirno /se /se
furina /se /se
yanami /se /se
yamada /se /se
sayaka /se /se
konata /se /se
蓝仙未未 /se /se 
*/
namespace TYX_YNXK{
	#define il inline
	#define vd void
	#define bl bool
	#define ll long long
	#define ull unsigned ll
	#define db double
	#define ldb long db
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define MP make_pair
	#define pb push_back
	#define N 505
	#define INF
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il unsigned read(){
		unsigned x=0;char c;
		for(;ch<48||ch>57;c);
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return x;
	}
	#undef c
	const int mod=998244353;
	il int add(int a,int b){return (a+=b)>=mod&&(a-=mod),a;}
	il int del(int a,int b){return (a-=b)<0&&(a+=mod),a;}
	il int qpow(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)r=1ll*r*a%mod;return r;}
	int jc[N],ic[N];
	il int C(int a,int b){if(a<b)return 0;return 1ll*jc[a]*ic[b]%mod*ic[a-b]%mod;}
	int n,m,tong[N],s[N];char ch[N];bl live[N];bl flag=1;
	namespace subtask1{
		int f[18+5][18+5][(1<<18)+5],ans;
		il vd solve(){
			f[0][0][0]=1;
			for(int i=0;i<n;i++){
				for(int k=0;k<=i;k++){
					for(int j=0;j<(1<<n);j++)if(f[i][k][j]){
						for(int p=1;p<=n;p++)if(((j>>(p-1))&1)^1){
							if(s[p]<=k||!live[i+1])f[i+1][k+1][j|(1<<(p-1))]=add(f[i+1][k+1][j|(1<<(p-1))],f[i][k][j]);
							else f[i+1][k][j|(1<<(p-1))]=add(f[i+1][k][j|(1<<(p-1))],f[i][k][j]);
						}
					}
				}
			}
			for(int k=0;k<=n-m;k++)ans=add(ans,f[n][k][(1<<n)-1]);
			printf("%d",ans);
		}
	}
	namespace subtask2{
		int f[N][N][N],ans;
		il vd solve(){
			if(!tong[0])return printf("%d",jc[n]),void(0);
			sort(s+1,s+1+n);
			f[1][0][0]=1;
			for(int i=1;i<n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i;k++)if(f[i][j][k]){
//						cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
						if(s[i+1]==s[i]){
							f[i+1][j][k]=add(f[i+1][j][k],1ll*f[i][j][k]*(i+1-j)%mod);
							f[i+1][j+1][k+1]=add(f[i+1][j+1][k+1],1ll*f[i][j][k]*j%mod);
						}else{
							if(j+s[i+1]-s[i]>i){
								if(k+n-i>=m)ans=add(ans,1ll*f[i][j][k]*C(n,i)%mod*jc[n-i]%mod);
							}else{
								int J=j;j+=s[i+1]-s[i];
								f[i+1][j][k]=add(f[i+1][j][k],1ll*f[i][J][k]*(i+1-j)%mod);
								f[i+1][j+1][k+1]=add(f[i+1][j+1][k+1],1ll*f[i][J][k]*j%mod);
								j=J;
							}
						}
					}
				}
			}
			for(int j=0;j<=n;j++)for(int k=m;k<=n;k++)ans=add(ans,f[n][j][k]);
			printf("%d",ans);
		}
	}
	namespace subtask3{
		int f[N],ans,pre[N];
		il vd solve(){
			pre[0]=tong[0];for(int i=1;i<=n;i++)pre[i]=pre[i-1]+tong[i];
			f[0]=1;//前 i 个数。
			int cnt=0;
			for(int i=0;i<n;i++){
				if(!live[i+1])f[i+1]=f[i],++cnt;
				else f[i+1]=1ll*(pre[i]-(i-cnt))*f[i]%mod;
			}
			ans=1ll*f[n]*jc[cnt]%mod;
			printf("%d\n",del(jc[n],ans));
		}
	}
	signed main(){
		jc[0]=1;for(int i=1;i<=N-5;i++)jc[i]=1ll*i*jc[i-1]%mod;
		ic[N-5]=qpow(jc[N-5],mod-2);for(int i=N-5;i;i--)ic[i-1]=1ll*i*ic[i]%mod;
		n=read(),m=read(),scanf("%s",ch+1);
		for(int i=1;i<=n;i++)live[i]=ch[i]-'0',flag&=live[i];
		for(int i=1;i<=n;i++)s[i]=read(),++tong[s[i]];
		if(!flag&&m==n)return puts("0"),0;
		if(n<=18){
			subtask1::solve();
		}else
		if(flag){
			subtask2::solve();
		}else
		if(m==1){
			subtask3::solve();
		} 
		return 0;
	}
}signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 512MB
*/
/*
3 2
111
0 1 2
*/
/*
起码 300 了吧。还有 2h 看能不能做出来。
看到数据范围 500 我很不好。看到取模我很不好。 
n 个人应聘，至少录用 m 个人。
决定顺序，即确定一个排列。然后我们有 n 套题，1 是可做题，0 是不可做题。
然后说一个人最多接受前面有 <ci 个人不面试，多了它就不做了。
然后考虑有多少排列满足录了 >=m 个人。
看起来还好是怎么说？感觉 y*f，t*r，z*y 甚至是 z*n 可能都会。
排列问题考虑插入 dp。但这个问题不好插入 dp，因为每个位置是不同的。
首先我们只需要判断 1 的位置即可，0 的位置都是死人。

考虑困难点在哪里。无非就是不同的 c 对应不同的判断，故必须考虑剩余集合。
考虑 A 性质，所有人都可以过。但我们发现出题人有 c=0。那 A 性质也不太好做了。

虽然我说插入 dp 不好做，但是对于这种问题好像也只能插入了。
考虑 c=0 插入哪里哪里去世。
对于 c=1，前面一个死人都不能有。
c=2 前面至多俩死人。

发现什么没有？死人堆不会影响活人堆。也就是说原来是活人的人现在死求不了了。
f[i][j] 表示插入了 c<=i 个人，第 i+1 个死人在第 j 个位置的方案数。
转移就考虑一个一个插，n^3。

上面的思路还要给的更精细一点。
一开始我们有一坨 0。当插入 1 的时候，第一个 0 前面是活人区，后面都是死亡区。
考虑记所谓第一个 0 的位置，插完所有一以后第一个 0 后面全是死人。
对于接下来的 2 来说，第一个 0 后面不是死亡区了，第二个 0 才是。于是考虑把第一个 0 向后移一位，做同样的操作。
更精细的方程就是 f[i][j][k] 表示前 i 个数，第一个 0 在第 j 位，选了 k 个数的方案数。转移特判 c 变化时。

考虑拓展。
插在后面无论如何都是死人，关键在于现在插在前面也可以是死人，还可以把活人搞死。
一个我觉得很有机会的想法是开局就把必死之人考虑进去。
我们记一下还有几个必死位没填，然后随时考虑把必死位填了。
这时你考虑你插哪。这个时候的插法会有人数限制，很难受，非常不适合插入 dp。

先考虑 B 性质，只有 18 个 1 可以插。
直接把 18 个 1 被插的状态记下来。本来想记 3^18 的，但过不了。
我们必须考虑前面的 1 是被插后是死人还是活人。没被插的 1、被插死的 1、被插活的 1 完全不一样。

算了还是考虑 m=1 和 m=n 的吧。
m=n 的必要条件就是全 1，这其实是全 1 那一档的特化。
m=1 即求死光了的方案。
考虑这样：
从左往右填数。由于前面全是死人所以能填哪些数是固定的。超过的前面填不了也是确定的。进而确定了方案。
好像确定不了。必死位实际上还是可以随便填，这个时候就得考虑后面了。
看来 m=1 我并不会。 

于是：不会 9~14，18~25，期望得分 44pts。
由于这是 T4，先打。 

考虑到底怎么求死光了的方案数。
注意到一个事实：如果你留出了安全区，那接下来这一坨会一直是安全区。
换句话说一点安全区都不能留。

打出 m=1 了，期望得分 56pts。 
*/
