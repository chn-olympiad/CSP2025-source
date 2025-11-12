#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
#define pb push_back
using namespace std;
int n,m;
const int N=1000099;
char _nan[N];
int c[N];
ll jc[N];
const ll mod=998244353;
int sumnan,suml;
ll dp[20][20][(1<<18)];
int siz[1<<20];
vector<int>jh[N];
int lowbit(int x){
	return x&(-x);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jh[0].pb(0);
	FOR(i,1,(1<<n)-1)siz[i]=siz[i-lowbit(i)]+1,jh[siz[i]].pb(i);
	jc[0]=1;
	FOR(i,1,n)jc[i]=jc[i-1]*i%mod;
	scanf("%s",_nan+1);
	FOR(i,1,n)scanf("%d",&c[i]);
	FOR(i,1,n)sumnan+=_nan[i]=='1'?1:0,suml+=c[i]==0?1:0;
	if(m==n){
		if(sumnan!=n || suml!=0)puts("0");
		else printf("%lld\n",jc[n]);
		return 0;
	}
	if(m==1){
		sort(c+1,c+1+n);
		int cnt=1;
		ll ans=1;
		int yicnt=0;
		FOR(i,1,n){
			if(_nan[i]=='1'){
				while(cnt<=n && i-1>=c[cnt])++cnt;
				if(cnt-1-yicnt<=0)ans=0;
				ans=(ll)ans*(cnt-1-yicnt)%mod;
				++yicnt;
			}
		}
		ans=(ll)ans*jc[n-yicnt]%mod;
		printf("%lld\n",(jc[n]-ans+mod)%mod);
		return 0;
	}
	dp[0][0][0]=1;
	FOR(i,0,n-1){
		FOR(j,0,i){
			for(int S:jh[i]){
				FOR(x,1,n){
					if(((1<<(x-1))&S))continue;
					int ad=(j>=c[x])?1:0;
					if(_nan[i+1]=='0')ad=1;
					(dp[i+1][j+ad][S|(1<<(x-1))]+=dp[i][j][S])%=mod;
				}
			}
		}
	}
	ll ans=0;
	FOR(i,m,n)(ans+=dp[n][n-i][(1<<n)-1])%=mod;
	printf("%lld",ans);
	return 0;
}