#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod=998244353;
const int N=5005,M=1e4+5;
int n,m,a[N];
ll f[M+5],g[M+5],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	f[0]=1;f[a[1]]++;f[a[2]]++;f[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		for(int j=M-a[i];j>=a[i]+1;j--)
			(g[j+a[i]]+=f[j])%=mod;
		(ans*=2)%=mod;
		for(int j=M;j>M-a[i];j--){
			(ans+=f[j])%=mod;
		}
		for(int j=M-a[i];j>=0;j--)
			(f[j+a[i]]+=f[j])%=mod;
	}
	for(int i=1;i<=M;i++){
		(ans+=g[i])%=mod;
//		printf("%d ",f[i]);
	}
//	putchar('\n');
	printf("%lld\n",ans);
	return 0;
}