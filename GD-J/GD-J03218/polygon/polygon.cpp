#include "bits/stdc++.h"
using namespace std;
#define int long long
static const int mod=998244353;
int n,ans,maxa;
int a[5005],f[2][10001][2];
int qpow(int a,int b){
	if(b==0) return 1;
	int ans=qpow(a,b>>1);
	return ans*ans%mod*(b&1?a:1)%mod;
}
int MOD(int x){
	return x>=mod?x-mod:x;
}
signed main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxa=max(maxa,a[i]);
	sort(a+1,a+n+1);
	f[0][0][0]=1;
	for(int i=1,now=1;i<=n;i++,now^=1){
		int res=qpow(2,i-1);
		for(int j=0;j<=2*maxa;j++){
			f[now][j][0]=MOD(f[now^1][j][0]+f[now^1][j][1]);
			if(j>=a[i]) f[now][j][1]=MOD(f[now^1][j-a[i]][0]+f[now^1][j-a[i]][1]);
		}
		for(int j=0;j<=a[i]*2;j++)
			res=MOD(res-f[now][j][1]+mod);
		ans=(ans+res)%mod;
		memset(f[now^1],0,sizeof f[now^1]);
	}cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
}
