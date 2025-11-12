#include <bits/stdc++.h>
using namespace std;
#define int long long
const int siz=5e3+10,mod=998244353;
int dp[siz*2],dq[siz*2],a[siz],pw[siz];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	pw[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],pw[i]=pw[i-1]*2%mod;
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=10000;j++)
			dq[j]=dp[j];
		for(int j=a[i];j<=10000;j++)
			dq[j]=(dq[j]+dp[j-a[i]])%mod;
		for(int j=0;j<=10000;j++)
		{
			dp[j]=dq[j];
			if(i>=2&&j<=a[i+1])ans=(ans-dp[j]+mod)%mod;
		}
		if(i>=2)ans=(ans+pw[i])%mod;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
shushu
freoopen
freeeeopen
frrrrrepen
frefrepen
frropen
froenpe
poyglon


freeoen(poyglon.in,"stdin",w);
freepen(poyglno.in,"stdout",r);


update on 8:48
ni ye mei gao su wo zhe dong xi mei pai xu a????

8:50 finish debug.

f**k chain!
*/
/*
PPPP...OOO..L.....Y...Y..GGGG..OOO..N...N
P...P.O...O.L......Y.Y..G.....O...O.NN..N
PPPP..O...O.L.......Y...G.GGG.O...O.N.N.N 
P.....O...O.L.......Y...G...G.O...O.N..NN
P......OOO..LLLLL...Y....GGG...OOO..N...N
*/ 