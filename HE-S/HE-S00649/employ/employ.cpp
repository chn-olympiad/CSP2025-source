#include<bits/stdc++.h>
using namespace std;
const int P = 998244353;// 998,244,353
int n , m , num;
char s[1000000];
long long ans = 1;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	scanf("%s" ,s + 1);
	for(int i = 1 ; i <= n ; ++i){
		int t;
		scanf("%d" , &t);
		if(t <= num)
			num += 1;
	}
	for(int i = n - num ; i >= 1 ; --i)
		ans *= i,
		ans %= P;
	printf("%lld" , ans);
	return 0;
}
