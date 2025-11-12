#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
const ll Mod = 998244353;
ll n,a[N];



int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n <= 2){
		printf("0");
		return 0;
	}
	if(n == 3){
		ll sumn = 0 , maxn = 0;
		for(int i = 1;i<=n;i++){
			sumn += a[i];
			maxn = max(maxn,a[i]);
		}if(sumn > maxn * 2){
			printf("1");
			return 0;
		}else{
			printf("0");
			return 0;
		}
	}ll ans = 0;
	for(int bian = 3;bian <= n;bian++){
		for(int i = 1;i<=n - bian;i++){
			ll sumn = 0,maxn = 0;
			for(int j = i;j<=i + bian;j++){
				sumn += a[j];
				maxn = max(maxn,a[j]);
			}
			if(sumn > maxn * 2){
				ans++;
			}
		}
	}
	printf("%lld",ans % Mod);
	return 0;
}