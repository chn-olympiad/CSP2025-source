// GZ-S00334 王曦 贵阳华师一学校 
#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x=0; bool f=0; char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}

#define x first
#define y second
#define pb emplace_back
#define upb upper_bound
#define lowb lower_bound
#define fil(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

typedef long long LL;
typedef vector<int> VI;
typedef unsigned int ull; 
typedef pair<int,int> PII;
const int N=510,MOD=998244353;

int n,m; char ch[N];
int C[N][N],fc[N];
int a[N],s0[N],sc[N],c[N];
int f[2][N][N];

signed main() 
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,ch+1);
	rep(i,1,n) a[i]=(ch[i]-'0'),s0[i]=s0[i-1]+(a[i]==0);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),c[x]++;
	sc[0]=c[0]; rep(i,1,n) sc[i]=sc[i-1]+c[i];
	rep(i,0,N-1) {C[i][0]=1; rep(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;}
	fc[0]=1; rep(i,1,N-1) fc[i]=fc[i-1]*1ll*i%MOD;
	int p=0; f[p][0][0]=1;
	rep(i,0,n-1) {
		rep(j,0,i) rep(k,0,i) if(f[p][j][k]) {
			int cur=j+s0[i];
//			cerr<<i<<' '<<j<<' '<<k<<' '<<cur<<' '<<f[p][j][k]<<"\n";
			if(a[i+1]==0) {
				rep(x,0,min(k,c[cur+1]))
					f[!p][j][k-x]=(f[!p][j][k-x]+f[p][j][k]*1ll*C[c[cur+1]][x]%MOD*C[k][x]%MOD*fc[x])%MOD;
			} else {
				if(sc[cur]-(i-s0[i]-k)>=0) {
					rep(x,0,min(k,c[cur+1]))
						f[!p][j+1][k-x]=(f[!p][j+1][k-x]+f[p][j][k]*1ll*C[c[cur+1]][x]%MOD*C[k][x]%MOD*fc[x]%MOD
							*(sc[cur]-(i-s0[i]-k)))%MOD;
//					cerr<<i<<' '<<j<<' '<<k<<' '<<sc[cur]-(i-s0[i]-k)<<"\n";
				}
				f[!p][j][k+1]=(f[!p][j][k+1]+f[p][j][k])%MOD;
			}
//			cerr<<i<<' '<<j<<' '<<k<<' '<<cur<<' '<<f[p][j][k]<<"\n";
//			cerr<<f[!p][0][0]<<' '<<a[i+1]<<' '<<C[1][1]<<' '<<c[cur+1]<<"\n";
		}
		fil(f[p],0),p^=1;
	}
	int ans=0;
	rep(j,0,n) rep(k,0,n) if(f[p][j][k]) {
		int cur=j+s0[n];
//		cerr<<n<<' '<<j<<' '<<k<<' '<<cur<<' '<<f[p][j][k]<<"\n";
		if(n-cur<m) continue;
		ans=(ans+f[p][j][k]*1ll*C[n-sc[cur]][k]%MOD*fc[k])%MOD;
	}
	printf("%lld\n",ans*1ll*fc[s0[n]]%MOD);
//	cerr<<ans*1ll*fc[s0[n]]%MOD<<"\n";
	
//	cerr<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
	return 0;
}

