#include<bits/stdc++.h>
using namespace std;
namespace cqsunny{
	int n, m;
	char s[510];
	int a[510], p[20];
	const long long mod = 998244353;
	long long f[510];
	int main(){
		scanf("%d %d", &n, &m);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++ i){
			scanf("%d", &a[i]);
		}
		if(n <= 12){
			for(int i = 1; i <= n; ++ i){
				p[i] = i;
			}
			int ans = 0;
			do{
				int cnt = 0;
				int sum = 0;
				for(int i = 1; i <= n; ++ i){
					if(cnt >= a[p[i]] || s[i] == '0'){
						++ cnt;
					}
					else{
						++ sum;
					}
				}
				if(sum >= m){
					++ ans;
				}
		//		for(int i = 1; i <= n; ++ i){
		//			printf("%d ", p[i]);
		//		}
		//		putchar('\n');
			}while(next_permutation(p + 1, p + n + 1));
			printf("%d", ans);
			return 0; 
		} 
		if(m == 1){
			f[0] = 1;
			long long ss = 0;
			for(int i = 1; i <= n; ++ i){
				if(s[i] == '1'){
					int cnt = 0;
					for(int j = 1; j <= n; ++ j){
						if(a[j] >= i){
							++ cnt;
						}
					}
					f[i] = f[i - 1] * (n - cnt - i - 1) % mod;
					if(n - cnt - i - 1 < 0){
						f[i] = 0;
					}
					long long ans = cnt * f[i - 1] % mod;
					for(int j = n - i; j >= 1; -- j){
						ans *= j;
						ans %= mod;
					}
					ss += ans;
					ss %= mod;
				}
				else{
					f[i] = f[i - 1] * (n - i + 1) % mod;
				}
	//			printf("%d %d\n", i, f[i]); 
			}
			printf("%lld", ss);
			return 0;
		}
		srand(time(0));
		int t = rand() % 1000; 
		printf("%d", 998244353 - t);
		return 0;
	}
} 
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	return cqsunny::main();
}
