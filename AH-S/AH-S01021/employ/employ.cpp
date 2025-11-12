#include<bits/stdc++.h>
#define ll long long
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int MAXN=500+10,MOD=998244353;
int n,m,s[MAXN],c[MAXN],cnt[MAXN];string S;
ll frac[MAXN],dp[2][MAXN][MAXN],tmp[MAXN][MAXN],pre[MAXN],C[MAXN][MAXN];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>S;
	ffor(i,1,n) s[i]=S[i-1]-'0';
	ffor(i,1,n) cin>>c[i],cnt[c[i]]++;
	pre[0]=cnt[0];
	ffor(i,1,n) pre[i]=pre[i-1]+cnt[i];
	frac[0]=1; ffor(i,1,n) frac[i]=frac[i-1]*i%MOD;
	ffor(i,0,n) {C[i][0]=1;ffor(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;}
	dp[0][0][0]=1;
	ffor(i,1,n) {
		int st=i&1,lst=st^1;
		memset(dp[st],0,sizeof(dp[st])),memset(tmp,0,sizeof(tmp));
		ffor(j,0,i-1) ffor(k,0,i-1) if(dp[lst][j][k]) {
			if(s[i]==0) tmp[j+1][k]+=dp[lst][j][k],tmp[j+1][k+1]+=dp[lst][j][k];
			else dp[st][j][k+1]+=dp[lst][j][k],tmp[j+1][k]+=dp[lst][j][k];
		}
		ffor(j,1,i) ffor(k,0,i) if(tmp[j][k]) {
			if(tmp[j][k]>=MOD) tmp[j][k]-=MOD;
			int p=pre[j-1];
			if(p-i+k>=0) ffor(s,0,min(k,cnt[j])) dp[st][j][k-s]+=tmp[j][k]*C[k][s]%MOD*C[p-i+k+cnt[j]-s][cnt[j]-s]%MOD;
		}
		ffor(j,0,i) ffor(k,0,i) if(dp[st][j][k]) dp[st][j][k]%=MOD;
	}
	ll res=0;
	ffor(i,0,n-m) {
		ll mul=1,sum=0;
		ffor(s,i+1,n) mul=mul*C[sum+cnt[s]][cnt[s]],mul%=MOD,sum+=cnt[s];
		res=(res+mul*dp[n&1][i][sum])%MOD;
	}
	ffor(i,0,n) res=res*frac[cnt[i]]%MOD;
	cout<<(res%MOD+MOD)%MOD;
	return 0;
}
