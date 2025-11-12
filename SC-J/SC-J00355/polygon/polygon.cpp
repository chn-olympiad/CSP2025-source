#include<bits/stdc++.h>
using namespace std;
long long n;
const long long N=5009,Q=998244353;
long long a[N],maxa;
long long f[N][N];
long long pow2[N];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	pow2[0]=1;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxa=max(maxa,a[i]);
		pow2[i]=pow2[i-1]*2%Q;
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<=maxa;i++)f[0][i]=1;
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<=maxa;j++){
			f[i][j]=f[i-1][j];
			if(j-a[i]>=0)
				f[i][j]=(f[i][j]+f[i-1][j-a[i]])%Q;
		}
	for(long long i=1;i<=n;i++){
		ans=(ans+pow2[i-1]-f[i-1][a[i]]+Q)%Q;
	}
	printf("%lld\n",ans);
}