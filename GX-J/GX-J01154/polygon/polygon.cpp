#include<iosteam>
using namespace std;
long long n,a[500005],ans;
const mod = 998244353;
	
			
int main(){
	freopen(polygon.in,"r",stdin);
	freopen(polygon.out,"w",stdout);
	scanf("%^lld",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=(b(i-1))+a[i];
	}
	sort(a+1;a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			print("1");
		}else print("0");
	}
	if(a[n]==1){
		for(int i = 3;i<=n;i++){
			ans=(ans(n-1)*n)%mod;
		}
		ans=(ans+_1)%mod;
		print("%lld",ans)
	}
	print("%lld",ans)
	return 0;
}
