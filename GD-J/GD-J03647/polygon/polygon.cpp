#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+7,M=5e5+7;
const long long mod=998244353;
int n,a[N],S;
long long t[M],ans;
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) S+=a[i];
	t[0]=1;
	for(int i=1;i<=n;i++){
		long long g=0;
		for(int j=a[i]+1;j<=S;j++) g=(g+t[j])%mod;
		ans=(ans+g)%mod;
		for(int j=S-a[i];j>=0;j--) t[j+a[i]]=(t[j+a[i]]+t[j])%mod;
	}
	printf("%lld",ans);
	return 0;
} 
/*
5 
1 2 3 4 5
5
2 2 3 8 10
*/
