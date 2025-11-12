#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=30;
const ll mod=998244353;
ll n,m,ans,c[N],f[262150][N];
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) c[i]=read();
	f[0][0]=1;
	for (int i=0;i<(1<<n);i++){
		ll sum=0;
		for (int j=1;j<=n;j++) if((i>>(j-1))&1) sum++;
		for (int j=0;j<=n;j++){
			for (int k=1;k<=n;k++){
				if((i>>(k-1))&1) continue;
				if(sum-j<c[k]&&s[sum+1]=='1') f[i+(1<<(k-1))][j+1]=(f[i+(1<<(k-1))][j+1]+f[i][j])%mod;
				else f[i+(1<<(k-1))][j]=(f[i+(1<<(k-1))][j]+f[i][j])%mod;
			}
		}
	}
	for (int i=m;i<=n;i++) ans+=f[(1<<n)-1][i];
	printf("%lld\n",ans);
	return 0;
}
