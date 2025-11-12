#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using VI=vector<int>;
using PII=pair<int,int>;
#define MP make_pair
#define fi first
#define se second
#define PB emplace_back
#define PPB pop_back
#define endl ('\n')
#define ALL(x) (x).begin(),(x).end()

const int N=505,MOD=998244353;
int n,m;
string s;
int cnt[N],sfx[N];

int fac[N],ifac[N];
int pw(int x,int y=MOD-2)
{
	int r=1;
	while(y)
	{
		if(y&1)r=1ll*r*x%MOD;
		x=1ll*x*x%MOD,y>>=1;
	}
	return r;
}
int C(int x,int y){return x>=y&&y>=0?1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD:0;}

int dp[2][N][N];

int main()
{
#ifndef LOCAL
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>n>>m>>s,s="$"+s;
	for(int i=1,x;i<=n;i++)cin>>x,cnt[x]++;
	for(int i=n;~i;i--)sfx[i]=sfx[i+1]+cnt[i];
	fac[0]=ifac[0]=1; for(int i=1;i<=n;i++)ifac[i]=pw(fac[i]=1ll*i*fac[i-1]%MOD);
	dp[0][0][n-cnt[0]]=1;

	for(int i=0,c=0,d=1;i<n;i++,swap(c,d))
	{
		for(int j=0;j<=i+1;j++)
			for(int k=0;k<=sfx[j+1];k++)dp[d][j][k]=0;
		for(int j=0;j<=i;j++)
			for(int k=0;k<=sfx[j+1];k++)
			{
				int cr=dp[c][j][k];
				if(!cr)continue;
				// cerr<<i<<" "<<j<<" "<<k<<" "<<cr<<endl;

				// still have patience
				if(k)
				{
					if(s[i+1]=='1')
						(dp[d][j][k-1]+=cr)%=MOD;
					else
					{
						for(int l=0;l<=min(k-1,cnt[j+1]);l++)
							dp[d][j+1][k-1-l]=(dp[d][j+1][k-1-l]+1ll*cr*C(cnt[j+1],l)%MOD*fac[sfx[j+1]-k+1]%MOD*ifac[(sfx[j+1]-k+1)-(cnt[j+1]-l)])%MOD;
					}
				}

				// unpatience
				for(int l=0;l<=min(k,cnt[j+1]);l++)
					dp[d][j+1][k-l]=(dp[d][j+1][k-l]+1ll*cr*C(cnt[j+1],l)%MOD*fac[sfx[j+1]-k]%MOD*ifac[(sfx[j+1]-k)-(cnt[j+1]-l)]%MOD*(n-i-k))%MOD;
			}
	}
	
	int ans=0;
	for(int i=0;i<=n-m;i++)
		ans=(ans+1ll*fac[sfx[i+1]]*dp[n&1][i][0])%MOD;
	cout<<ans<<endl;

	return 0;
}