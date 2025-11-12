#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5007,M=998244353;
int a[N],f[N][N],pw[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	scanf("%lld",&n),pw[0]=1;
	for (int i=1;i<=n;++i)
		scanf("%lld",a+i),pw[i]=pw[i-1]*2%M;
	sort(a+1,a+n+1),f[0][0]=1;
	for (int i=1;i<=n;++i){
		for (int j=0;j<=5000;++j){
			f[i][j]=f[i-1][j];
			if (j>=a[i]) (f[i][j]+=f[i-1][j-a[i]])%=M;
		}
		int sum=pw[i-1];
		for (int j=0;j<=a[i];++j)
			(sum+=M-f[i-1][j])%=M;
		(ans+=sum)%=M;
	}
	printf("%lld",ans);
	return 0;
}
/*
AKed in 45 minutes
start to be garner
I think D is at most upper yellow
aaa i have to sit here for 2.5 hours
*/