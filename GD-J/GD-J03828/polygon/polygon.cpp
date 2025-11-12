#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5005;
int n,a[N];
ll ans,f[N][N],mod=998244353ll;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=5001;j++) ans=(ans+f[i-1][j])%mod;
		}
		for(int j=0;j<=5001;j++){
			int k=j+a[i];
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if(k>5000) f[i][5001]=(f[i][5001]+f[i-1][j])%mod;
			else f[i][k]=(f[i][k]+f[i-1][j])%mod; 
		} 
	}
	printf("%lld",ans);
	return 0;
}
