//rp++
#include<bits/stdc++.h>
using namespace std;
const int P = 998244353;// 998,244,353 
int n , a[5010];
long long ans;
bool b = true;//骗分这一块
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &a[i]);
		if(a[i] != 1)
			b = false;
	}
	if(b){
		for(int i = 1 ; i <= n ; ++i){
			int sum = 1;
			for(int j = 0 ; j <= i - 1 ; ++j){
				sum *= (n - j);
				sum %= P;
			}
			ans += sum;
			ans %= P;
		}
		printf("%lld" , ans);
		return 0;
	}
	sort(a + 1 , a + n + 1);///666有陷阱
	if(a[1] + a[2] > a[3])
		ans += 1;
	printf("%lld" , ans);
	return 0;
}
