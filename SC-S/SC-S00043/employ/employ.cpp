#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;int f=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x*=f; 
}

//
const int N=19,mod=998244353;
int n,m,c[N],is[N],ans,st,used[N],f[N][(1<<N-1)+100];
char s0[N];
signed main()
{
	cin.tie(0)->sync_with_stdio(0); 
//	freopen("my.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s0+1);
	rep(i,1,n)
		is[i]=(s0[i]=='1');
	rep(i,1,n)cin>>c[i];
	f[0][0]=1;
	st=(1<<n)-1;
	rep(s,0,st)
	{
		rep(j,1,n)if(!(s&(1<<j-1)))
		{
			int t=(s|1<<j-1);
			int o=__builtin_popcount(s)+1;
			rep(k,0,n)
			{
				int tmp=(k>=c[j]||is[o]==0);
				f[k+tmp][t]+=f[k][s];
				f[k+tmp][t]%=mod;
			}
		}
	}
	rep(i,m,n)ans+=f[n-i][st],ans%=mod;
	cout<<ans%mod; 
	return 0;
}