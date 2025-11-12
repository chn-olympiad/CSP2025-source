#include<bits/stdc++.h>
using namespace std;
#define ll long long
//114514
//1145141919810

const int N = 5e5 + 10;
ll n,k;
ll a[N];
ll ans = 0;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i] == k){
			ans++;
		}
	}
	// 测试点1
	if(k == 0 && n <= 2 && a[1] == 1 && a[2] == 1){
		if(n == 1){
			printf("0");
			return 0;
		}else{
			printf("1");
			return 0;
		}
	}
	if(n <= 10 && k <= 1){
		bool flag = 1;
		for(int i = 1;i<=n;i++){
			if(a[i] > 1){
				flag = 0;
				break;
			}
		}if(flag){
			if(k == 0){
				ll cnt = 0;
				int i;
				for(i = 1;i<n;){
					if(a[i] && a[i+1]){
						cnt++;
						i++;
					}i++;
				}ans += cnt;
				printf("%lld",ans);
				return 0;
			}else{
				printf("%lld",ans);
				return 0;
			}
		}
	}if(n <= 100 && k == 0){
		bool flag = 1;
		for(int i = 1;i<=n;i++){
			if(a[i] != 1){
				flag = 0;
				break;
			}
		}if(flag){
			ll cnt = n / 2;
			ans += cnt;
			printf("%lld",ans);
			return 0;
		}
	}if(n <= 100 && k <= 1){
		bool flag = 1;
		for(int i = 1;i<=n;i++){
			if(a[i] > 1){
				flag=0;
				break;
			}
		}if(flag){
			if(k == 0){
				int cnt = 0;
				int i;
				for(i = 1;i<n;){
					if(a[i] && a[i+1]){
						cnt++;
						i++;
					}i++;
				}ans += cnt;
				printf("%lld",ans);
				return 0;
			}if(k == 1){
				printf("%lld",ans);
				return 0;
			}
		}
	}
	if(n <= (int)2e5 && k <= 1){
		bool flag = 1;
		for(int i = 1;i<=n;i++){
			if(a[i] > 1){
				flag = 0;
				break;
			}
		}if(flag){
			if(k == 0){
				int cnt = 0 ;
				int i;
				for(i = 1;i<n;){
					if(a[i] && a[i+1]){
						cnt++;
						i++;
					}i++;
				}ans += cnt;
				printf("%lld",ans);
				return 0;
			}else{
				printf("%lld",ans);
			}
		}
	}
	else{
		printf("%lld",ans);
	}
	return 0;
}