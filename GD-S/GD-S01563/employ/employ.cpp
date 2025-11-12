#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define N 100005
#define M (1<<18)+7
#define int long long
using namespace std;
const int INF=1e18;
const int mod=998244353;
int n,m,c[N],f[M][20],ans=0;
char s[N];
int num[M],id[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if((i&(1<<j-1))&&s[j]=='0') num[i]++;
			if(i&(1<<j-1)) id[i]++;
		}
//		cout<<i<<" "<<id[i]<<endl;
	}
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(!(i&(1<<j-1))) continue;
			for(int k=0;k<=n;k++){
				if(c[j]>k&&s[id[i]]=='1') f[i][k]+=f[i^(1<<j-1)][k],f[i][k]%=mod;
				else f[i][k+1]+=f[i^(1<<j-1)][k],f[i][k+1]%=mod;
			}
		}
	}
//	for(int i=0;i<(1<<n);i++) for(int j=0;j<=n;j++) if(f[i][j]) cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
	printf("%lld",ans); 
	return 0;
}
