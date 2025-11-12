#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b){
	return a > b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,ans = 0;
	cin >> t;
	long long a[1000010];  
	long long b[1000010];
	long long c[1000010];
	for(long long x = 1; x <= t; x++){
		long long n;
		cin >> n;
		bool flag1 = 1;
		bool flag2 = 1;
		bool flag3 = 1;
		bool flag4 = 1;
		for(long long i = 1; i <= n; i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(b[i] != 0 || c[i] != 0){
				flag1 = 0;
			}if(c[i] != 0 || a[i] != 0){
				flag2 = 0;
			}if(b[i] != 0 || a[i] != 0){
				flag3 = 0;
			}if(c[i] != 0){
				flag4 = 0;
			}
		}
		if(flag1 == 1){
			sort(a+1,a+1+n,cmp);
			for(long long i = 1; i <= n/2; i++){
				ans += a[i];
			}
			cout << ans;
		}else if(flag2 == 1){
			sort(b+1,b+1+n,cmp);
			for(long long i = 1; i <= n/2; i++){
				ans += b[i];
			}
			cout << ans;
		}else if(flag3 == 1){
			sort(c+1,c+1+n,cmp);
			for(long long i = 1; i <= n/2; i++){
				ans += c[i];
			}
			cout << ans;
		}else if(flag4 == 1){
			sort(a+1,a+1+n,cmp);
			sort(b+1,b+1+n,cmp);
			for(long long i = 1; i <= n/2;i++){
				ans += a[i];
				ans += b[i];
			}
			cout << ans;
		}
	}    
	return 0;
} 
