#include<bits/stdc++.h>
using namespace std;
#define int long long
char ibuf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++) 
#define per(i,r,l) for(int i=r;i>=l;i--)
#define endl '\n'
inline void read(int &x)
{
	x=0;int f=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x*=f;
}

//
const int N=5e3+12;
const int mod=998244353;
int a[N],n,tot,ans,fl=1,inv[N],fc[N],f[N*N],m;
bool b[N];
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void init()
{
	fc[0]=1;
	rep(i,1,n)fc[i]=fc[i-1]*i%mod;
	inv[n]=qpow(fc[n],mod-2);
	per(i,n-1,0)inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int x,int y)
{
	return fc[x]*inv[y]%mod*inv[x-y]%mod;
}
void solve2()
{
	init();
//	rep(i,1,n)cout<<fc[i]*inv[i]%mod<<'\n';
	rep(i,3,n)ans=(ans+C(n,i))%mod;
	cout<<ans;
	exit(0);
}
signed main()
{
//	cin.tie(0)->sync_with_stdio(0);
//	freopen("my.in","r",stdin);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	rep(i,1,n)
	{
		read(a[i]),tot+=a[i];
		if(a[i]!=1)fl=0;
	}
	if(fl)solve2();
	m=tot;
	sort(a+1,a+1+n);
	f[0]=1;
	rep(i,1,n)
	{
		per(j,m,a[i]+1)
		{
			ans+=f[j];
			ans%=mod;
			}	
		
		per(j,m,0)if(f[j])if(j+a[i]<=m)
			f[j+a[i]]+=f[j],f[j+a[i]]%=mod;
	}
	cout<<ans;
	return 0;
}