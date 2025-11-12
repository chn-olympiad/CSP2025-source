#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],fac[N],inv[N];
string a;
void add(int &x,int y) {(x+=y)>=mod&&(x-=mod);}
int A(int n,int m) {return n<m||m<0?0:1ll*fac[n]*inv[n-m]%mod;}
int C(int n,int m) {return n<m||m<0?0:1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;}
namespace force
{
	int f[1<<18][19];
	void solve()
	{
		f[0][0]=1;
		for(int s=0;s<(1<<n);s++)
		{
			int cnt=__builtin_popcount(s);
			for(int i=0;i<=cnt;i++) if(f[s][i])
				for(int j=0;j<n;j++) if(!(s>>j&1))
				{
					if(a[cnt+1]=='1'&&i<c[j+1]) add(f[s|(1<<j)][i],f[s][i]);
					else add(f[s|(1<<j)][i+1],f[s][i]);
				}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++) add(ans,f[(1<<n)-1][i]);
		cout<<ans<<"\n";
	}
}
namespace SB
{
	int f[2][N][N],tot[N],res[N];
	void solve()
	{
		int cnt0=0;
		for(int i=1;i<=n;i++) if(a[i]=='0') cnt0++;
		fac[0]=1; for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++) tot[c[i]]++;
		if(cnt0<tot[n]) {cout<<"0\n"; return;}
		int p=0,q=1; f[0][0][cnt0-tot[n]]=1;
		for(int i=n;i>=1;i--)
		{
			if(a[i]=='1')
			{
				memset(f[q],0,sizeof(f[q]));
				for(int j=0;j<n-cnt0;j++)
					for(int k=0;k<=cnt0;k++) add(f[q][j+1][k],f[p][j][k]);
				swap(p,q);
			}
			memset(f[q],0,sizeof(f[q]));
			for(int j=0;j<=n-cnt0;j++)
				for(int k=0;k<=cnt0;k++) if(f[p][j][k])
					for(int l=0;l<=tot[i-1];l++) if(l<=j&&tot[i-1]-l<=k)
					{
						add(f[q][j-l][k-(tot[i-1]-l)],1ll*f[p][j][k]*C(tot[i-1],l)%mod*A(j,l)%mod);
					}
			swap(p,q);
			// cerr<<"awa "<<i<<"\n";
			// for(int j=0;j<=n-cnt0;j++)
			// 	for(int k=0;k<=cnt0;k++) cerr<<j<<" "<<k<<" | "<<f[p][j][k]<<"\n";
		}
		int res=1ll*f[p][0][0]*fac[cnt0]%mod;
		cout<<(fac[n]-res+mod)%mod<<"\n";
	}
}
int qpow(int x,int y)
{
	int s=1;
	for(;y;x=1ll*x*x%mod,y>>=1) if(y&1) s=1ll*s*x%mod;
	return s;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>a,a=' '+a;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n;i>=1;i--) inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) {force::solve(); return 0;}
	if(m==n)
	{
		for(int i=1;i<=n;i++) if(a[i]=='0'||c[i]==0) {cout<<"0\n"; return 0;}
		cout<<fac[n]<<"\n";
		return 0;
	}
	SB::solve();
	return 0;
}