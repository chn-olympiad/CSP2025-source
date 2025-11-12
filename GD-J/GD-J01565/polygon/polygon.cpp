#include <bits/stdc++.h>
#define int long long
const int M=998244353;
using namespace std;
int a[5010];
int f[20010];
signed main(){
	int n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	int m=0;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		m+=a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	f[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=a[i]+1;j<=10000;j++){
			ans+=f[j];
			ans%=M;
		}
		for (int j=10000;j>=10000-a[i];j--){
			f[10000]+=f[j];
			f[10000]%=M;
		}
		for (int j=9999;j>=1;j--){
			if (j-a[i]>=0){
				f[j]+=f[j-a[i]];
				f[j]%=M;
			}
		}
//		printf("%lld\n",f[10000]);
//		for (int j=a[i]+1;j<=m;j++){
//			
	}
	printf("%lld",ans);
	return 0;
}

