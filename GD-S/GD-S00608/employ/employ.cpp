#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=510,P=998244353;
LL n,m,c[N];
char a[N];
namespace Deco
{
	LL f[1<<18][20];
	void upd(LL &x,LL y) { x=(x+y)%P; }
	void solve()
	{
		f[(1<<n)-1][0]=1;
		for(int s=(1<<n)-1;s>=0;s--)
		{
			LL pop=1;
			for(int i=0;i<n;i++) pop+=!(s>>i&1);
			for(int i=0;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(!(s>>(j-1)&1)) continue;
					if(i<c[j]&&a[pop]=='1') upd(f[s-(1<<(j-1))][i],f[s][i]);
					else upd(f[s-(1<<(j-1))][i+1],f[s][i]);
				}
			}
		}
		LL ans=0;
		for(int i=0;i<=n-m;i++) upd(ans,f[0][i]);
		printf("%lld",ans);
	}
}
void FlagA()
{
	for(int i=1;i<=n;i++) if(a[i]!='1') return;
	LL res=1;
	for(int i=1;i<=n;i++) res=res*i%P;
	printf("%lld",res); exit(0);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,a+1);
	for(int i=1;i<=n;i++) scanf("%lld",c+i);
	if(n<=18) return Deco::solve(),0;
	FlagA();
	return 0;
}
