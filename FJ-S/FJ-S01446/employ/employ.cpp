#include <bits/stdc++.h>
using namespace std;
const int N=505,T=1<<18,mod=998244353;
int md(int x)
{
	return x>=mod?x-mod:x;
}
void upd(int &x,int y)
{
	x=md(x+y);
}
int n,m,c[N],f[19][T],ans;
int fac[N],inv[N],invp[N];
char a[N];
int C(int x,int y)
{
	if (x<0||x>y) return 0;
	return 1ll*fac[y]*invp[x]%mod*invp[y-x]%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a);
	fac[0]=inv[0]=invp[0]=1;
	fac[1]=inv[1]=invp[1]=1;
	for (int i=2;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod,
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod,
		invp[i]=1ll*invp[i-1]*inv[i]%mod;
	for (int i=0;i<n;i++) scanf("%d",c+i);
	if (n<=18)
	{
		f[0][0]=1;
		for (int i=0;i<1<<n;i++)
			for (int j=0;j<n;j++)
			{
				if (i>>j&1) continue;
				int t=__builtin_popcount(i);
				for (int k=0;k<=t;k++)
					if (k>=c[j]||a[t]=='0')
						upd(f[k+1][i|1<<j],f[k][i]);
					else
						upd(f[k][i|1<<j],f[k][i]);
			}
	//	for (int i=0;i<1<<n;i++)
	//	{
	//		int t=__builtin_popcount(i);
	//		for (int j=0;j<=t;j++)
	//			if (f[j][i]) cerr<<i<<" "<<j<<" "<<f[j][i]<<endl;
	//	}
		for (int i=0;i+m<=n;i++) upd(ans,f[i][(1<<n)-1]);
		cout<<ans;
		return 0;
	}
	if (n==m)
	{
		bool f2=1;
		for (int i=0;i<n;i++) f2&=(c[i]>0&&a[i]=='1');
		if (f2) ans=fac[n];
		cout<<ans;
		return 0;
	}
	bool f1=1,f2=1;
	for (int i=0;i<n;i++) f1&=(a[i]=='1'),f2&=(c[i]>0);
	if (f1&&f2)
	{
		ans=fac[n];
		cout<<ans;
		return 0;
	}
	return 0;
}
