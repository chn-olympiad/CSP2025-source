#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define db double
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define low lower_bound
#define upp upper_bound
using namespace std;
namespace hwq{
	inline int read(){int x=0;bool f=0;char ch=getchar();while(!isdigit(ch)&&ch!='-') ch=getchar();if(ch=='-') f=1,ch=getchar();while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=getchar();return f?-x:x;}
	random_device R;
	mt19937 G(R());
	inline ll rd(ll l,ll r){return uniform_int_distribution<ll>(1ll,1ll<<62)(G);}
	const int MAXN=505;
	const ll MO=998244353;
	int n,m;
	char s[MAXN];
	int c[MAXN],a[MAXN],cnt[MAXN];
	ll f[2][MAXN][MAXN],g[1<<18][20];
	bool vis[MAXN];
	auto check=[](){
		int t=0;
//		for(int i=1;i<=n;i++) printf("%d ",c[a[i]]);
//		printf("\n");
		for(int i=1;i<=n;i++) if(s[i]=='1'&&(i-1-t)<c[a[i]]) t++;
		return t>=m; 
	};
	inline int dfs(int x){	
		if(x==n+1) return check();
		int ans=0;
		for(int i=1;i<=n;i++) if(!vis[i]) vis[i]=1,a[x]=i,ans+=dfs(x+1),vis[i]=0;
		return ans;
	}
	int main(){
		n=read(),m=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) c[i]=read();
		sort(c+1,c+n+1);
//		auto jia=[&](const ll &x,const ll &y){return x+y>=MO?x+y-MO:x+y;};
		auto J=[&](ll &x,const ll &k){(x+=k)>=MO&&(x-=MO);};
		if(n<=18){
			g[0][0]=1; //哪些人被用了，录取了多少人 
			for(int p=1;p<(1<<n);p++){
				int cnt=0;
				for(int i=0;i<n;i++) if(p&(1<<i)) cnt++;
				for(int i=0;i<n;i++) if(p&(1<<i)) for(int j=0;j<cnt;j++){
					J(g[p][j+(s[cnt]=='1'&&cnt-1-j<c[i+1])],g[p^(1<<i)][j]);
				}
			}
			ll ans=0;
			for(int i=m;i<=n;i++) J(ans,g[(1<<n)-1][i]);
			printf("%lld",ans);
			return 0;
		} 
		for(int i=1;i<=n;i++) cnt[c[i]]++;
		for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
		bool tag=0,pre=1;
		for(int i=0;i<=n;i++) f[tag][i][0]=1;
		for(int i=n;i>=1;i--){
			tag^=1,pre^=1;
			for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) f[tag][j][k]=0;
			for(int j=0;j<=n;j++) for(int k=0;k<=n;k++){
				if(k&&i-1-j>=0&&s[i]=='1') J(f[tag][j][k],f[pre][j+1][k-1]*max(0,cnt[n]-cnt[i-1-j]-k+1)%MO);
				if(i-1-j>=0) J(f[tag][j][k],f[pre][j][k]*max(0,cnt[i-1-j]-(i-1-j))%MO);
//				printf("f(%d,%d,%d)=%lld\n",i,j,k,f[tag][j][k]);
			}
		}
		ll ans=0;
		for(int i=m;i<=n;i++) J(ans,f[tag][0][i]);
		printf("%lld",ans);
		return 0;
	}
}
int main(){
//	while(1) //13
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	hwq::main();
	return 0;
}
/*
3 1
111
1 1 2
10 5
1111111111
6 0 4 2 1 2 5 4 3 3
ps：前几天才背了这个单词，服了
与人编号无关，先对ci排序，感觉比T3可做
但其实更难，不要红温！！！
从特殊性质出发
m=1至少有一个人被录取
一个人被录取，当且仅当s_i=1且前面未录取的人数<c_i 
WC再见，我完蛋了
现在应该还没上300，T4只会10的，呵呵目标250说是，一年了，T4还是上不了20
性质A，合法性仅与c的顺序有关
f(i,j)表示前i位，有j个人未被录取的方案数
才发现电脑没画图？？？什么鬼 
一个人没有被录取，当且仅当前面未被录取的人数>=c_i，且前面未被录取的人的c<=c_i 
f(i,j)= f(i-1,j)*(cnt[n]-cnt[j]-(i-j)) (Wrong!我不知道后面这部分有多少人已经被录取)
		f(i-1,j-1)*(cnt[j]-j)
倒着做？
后面i个人，前面需要j个被录取，后面有k个被录取 
f(i,j,k)=f(i+1,j+1,k-1)*(cnt[n]-cnt[j]-k+1)
f(i,j,k)=f(i+1,j,k)*(cnt[j]-j)
emmm好像有25？可以了可以了我知足了 
啊啊啊调不出来！！！ 
*/
