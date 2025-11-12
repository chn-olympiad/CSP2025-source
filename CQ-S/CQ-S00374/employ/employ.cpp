#include<bits/stdc++.h>
#define int long long
#define N 505
using namespace std;
int n,m;
int a[N];
int f[2][(1<<18)+5][20];
char s[N];
const int mod=998244353;
void sub1(){
	f[0][0][0]=1;
	int o=0;
	for(int i=1;i<=n;i++){
		o^=1;
		for(int j=0;j<(1<<n);j++)
			for(int k=0;k<=n;k++) f[o][j][k]=0;
		for(int j=0;j<(1<<n);j++){
			for(int k=0;k<=n;k++){
				if(!f[o^1][j][k]) continue;
				for(int l=0;l<n;l++){
					if(j>>l&1) continue;
					(f[o][j|(1<<l)][k+(s[i]=='1')*(a[l]>i-1-k)]+=f[o^1][j][k])%=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) (ans+=f[o][(1<<n)-1][i])%=mod;
	printf("%lld\n",ans);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sub1();
	return 0;
}
