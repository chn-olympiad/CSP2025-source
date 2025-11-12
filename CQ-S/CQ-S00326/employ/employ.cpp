#include<cstdio>
using namespace std;
typedef long long int L;
L n,a;
const L m = 998244353LL;
L pwd(L x,L y){
	L z = 1LL;
	while(y){
		if(y & 1LL){z = z * x % m;}
		x = x * x % m;
		y >>= 1LL;
	}
	return z;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld",&n);
	a = 1LL;
	for(L i = 1LL;i <= n;i++){
		a = a * i % m;
	}
	printf("%lld",&a);
	return 0;
}
