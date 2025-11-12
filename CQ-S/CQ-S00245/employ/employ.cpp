#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
mt19937 engine(chrono::steady_clock().now().time_since_epoch().count());
const int MOD=998244353;
const int MAXN=105;
const int MAXK=(1<<18);
string s;
int n,m,idx;
long long fac[MAXN],ifac[MAXN];
int a[MAXN],sum[MAXN],res[MAXN],p[MAXN];
void AddC(int &x,int y)
{
	if((x+=y)>=MOD) x-=MOD;
}
int Mul(int x,int y)
{
	return 1ll*x*y%MOD;
}
long long qpow(long long u,long long k)
{
	long long Ans=1;
	while(k) {
		if(k&1) Ans=Ans*u%MOD;
		k/=2;
		u=u*u%MOD;
	}
	return Ans;
}
long long inv(long long u)
{
	return qpow(u,MOD-2);
}
int C(int N,int M)
{
	return fac[N]*ifac[N-M]%MOD*ifac[M]%MOD;
}
int A(int N,int M)
{
	return fac[N]*ifac[N-M]%MOD;
}
void Init()
{
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) {
		fac[i]=fac[i-1]*i%MOD;
		ifac[i]=ifac[i-1]*inv(i)%MOD;
	}
}
int f[MAXN],g[MAXN];
void update(int N,int val)
{
	for(int i=0;i<=N;i++) {
		g[i]=f[i],f[i]=0;
	}
	for(int i=0;i<=N;i++) {
		for(int j=0;i+j<=N&&j<=val;j++) {
			AddC(f[i+j],Mul(g[i],Mul(A(val,j),C(N-i,j))));
		}
	}
}
int Force()
{
	for(int i=n;i>=0;i--) sum[i]+=sum[i+1];
	int Ans=0;
	for(int state=0;state<(1<<idx);state++) {
		int siz=__builtin_popcount(state);
		if(siz>m) continue;
		memset(res,0,sizeof(res));
		for(int i=1;i<=idx;i++) {
			if(!(state>>(i-1)&1)) res[p[i]]++;
		}
		for(int i=1;i<=n;i++) {
			if(a[i]=='0') res[i]++;
			res[i]+=res[i-1];
		}
		int last=0,tmp=0;
		memset(f,0,sizeof(f)),f[0]=1;
		vector<int>N;
		for(int i=idx;i>=1;i--) {
			if(!(state>>(i-1)&1)) continue;
			int val=sum[res[p[i]]+1]-last;
//			cout<<res[p[i]]+1<<" - "<<last<<'\n';
			last=sum[res[p[i]]+1];
			N.emplace_back(val);
		}
//		cout<<'\n';
		while(!N.empty()) {
			update(++tmp,N.back());
//			cout<<N.back()<<" ";
			N.pop_back();
		}
//		cout<<"\n";
		int sum=Mul(f[tmp],A(n-tmp,n-tmp));
//		cout<<"sum : "<<sum<<"\n";
		AddC(Ans,sum);
	}
	return Ans;
}
bool checkA()
{
	return m==n;
}
int SolveA()
{
	for(int i=1;i<=n;i++) {
		if(s[i]=='0') return 0;
	}
	return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s="&"+s;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum[a[i]]++;
		if(s[i]=='1') p[++idx]=i;
	}
	Init();
	if(idx<=18) {
		cout<<Force()<<"\n";
		return 0;
	}
	if(checkA()) {
		return SolveA();
	}
	return 0;
}
/*
input:
3 2
101
1 1 2
output:
2
*/
