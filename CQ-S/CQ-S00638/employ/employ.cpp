#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c[501],cnt[501];
ll f[502][502],g[502][502],pre[1001],inv[1001];
ll ans[1<<18][20];
char s[501];
const int mod=998244353;
int check(){
	for(int i=1;i<=n;i++) if(s[i]!='1') return 0;
	return 1;
}
ll qpow(ll a,ll b){
	ll s=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) s=s*a%mod;
	return s;
}
ll C(int n,int m){
	if(n<m||m<0) return n==m;
	return n<m||m<0?0:pre[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+1+n);
	pre[0]=inv[0]=1;
	for(int i=1;i<=n*2;i++) pre[i]=pre[i-1]*i%mod,inv[i]=qpow(pre[i],mod-2);
	if(check()){
		for(int i=1;i<=n;i++) cnt[c[i]]++;
		f[cnt[0]][cnt[0]]=pre[cnt[0]];
		int now=cnt[0];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=now;j++){
				for(int k=0;k<=cnt[i];k++){
					for(int l=0;l<=now;l++){
						int tot=now+1,B=j;
						(g[max(j+k-1,0)][l+k]+=f[j][l]*pre[cnt[i]]%mod*C(k+B-1,B-1)%mod*C(cnt[i]-k+tot-B-1,tot-B-1))%=mod;
					}
				}
			}
			now+=cnt[i];
			for(int j=0;j<=now;j++) for(int k=0;k<=now;k++) f[j][k]=g[j][k],g[j][k]=0;
		}
		ll s=0;
		for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) if(n-j>=m) (s+=f[i][j])%=mod;
		printf("%lld",s);
		return 0;
	}
	if(n<=18){
		ans[0][0]=1;
		for(int S=0;S<(1<<n);S++){
			int C=0;
			for(int i=0;i<n;i++) C+=S>>i&1;
			for(int j=0;j<=C;j++){
				for(int k=1;k<=n;k++){
					if(S>>(k-1)&1) continue;
					int T=S|(1<<(k-1));
					if(s[C+1]=='0') (ans[T][j+1]+=ans[S][j])%=mod;
					else{
						if(c[k]<=j) (ans[T][j+1]+=ans[S][j])%=mod;
						else (ans[T][j]+=ans[S][j])%=mod;
					}
				}
			}
		}
		ll now=0;
		for(int i=0;i<=n;i++) if(n-i>=m) (now+=ans[(1<<n)-1][i])%=mod;
		printf("%lld",now);
		return 0;
	}
	if(m==n){
		for(int j=1;j<=n;j++){
			if(!c[j]||s[j]=='0'){
				printf("0");
				return 0;
			}
		}
	}
	printf("%lld",pre[n]);
	return 0;
}
