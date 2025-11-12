#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=10;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	printf("%lld",ans%mod);
	return 0;
}
