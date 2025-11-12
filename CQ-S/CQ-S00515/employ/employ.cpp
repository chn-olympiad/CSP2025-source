#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define fi first
#define sd second
#define pb push_back
#define mk make_pair
#define endl '\n'
#define int long long
const int N=505,mod=998244353;
bool flag;
int n,m;
char s[N];
int c[N],fac[2005],inv[2005];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int n,int m)
{
	if(n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
namespace wilbur
{
	int f[N][N];
	int cnt[N];
	int main()
	{
		for(int i=1;i<=n;i++)cnt[c[i]]++;
		f[0][0]=fac[cnt[0]];
		int sum=cnt[0];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=sum;j++)//前 i-1 录取了 j 个人 
			{
				int x=sum-j;
				for(int k=0;k<=cnt[i];k++)//再录取了 k 个人 
				{
					int t=min(x,i-1),t2=x-t;
					f[i][j+k]=(f[i][j+k]+f[i-1][j]*C(j+1+t+k-1,j+1+t-1)%mod*C(t2+cnt[i]-k-1,t2-1)%mod*fac[cnt[i]]%mod)%mod;
//					cout<<i<<" "<<j+k<<" "<<t<<" t2+cnt[i]-k: "<<t2+cnt[i]-k<<" t2: "<<t2<<" "<<k<<" "<<cnt[i]<<" j+1+t: "<<j+1+t<<" k: "<<k<<" "<<f[i-1][j]<<" "<<C(j+1+t+k-1,j+t+1)<<" "<<C(t2+cnt[i]-k-1,t2)<<" "<<fac[cnt[i]]<<endl;
				}
			}
			sum+=cnt[i];
//			for(int j=0;j<=sum;j++)cerr<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
		int ans=0;
		for(int i=m;i<=n;i++)ans=(ans+f[n][i])%mod;
		cout<<ans<<endl;
		return 0;
	}
}
namespace wilbur2
{
	int ans;
	int p[N];
	int main()
	{
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				if(tot>=c[p[i]])
				{
					tot++;
					continue;
				}
				if(s[i]=='0')tot++;
			}
			if(n-tot>=m)ans++;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<endl;
		return 0;
	}
}
signed main()
{
//	freopen("employ2.in","r",stdin);
//	freopen("employ.out","w",stdout);
	flag=true;
	scanf("%lld %lld",&n,&m);
	fac[0]=inv[0]=1;
	scanf("%s",(s+1));
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=2000;i++)fac[i]=fac[i-1]*i%mod;
	inv[2000]=qpow(fac[2000],mod-2);
	for(int i=2000-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)if(s[i]!='1')flag=false;
	if(flag)wilbur::main();
	else if(n<=10)wilbur2::main();
	return 0;
}
/*
6 5
111111
0 1 2 2 3 3
360
*/
