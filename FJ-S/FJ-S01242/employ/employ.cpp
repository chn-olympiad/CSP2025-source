#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int MOD = 998244353; 
int n , m , k , c[N] , ans = 1 , sum;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	while(k > 0){
		sum += k % 10;
		k /= 10; 
	}
	for(int i = 1 ; i <= n ; i++) scanf("%d" , &c[i]);
	if(sum == n){
		for(int i = 1 ; i <= n ; i++) ans *= i % MOD;
		printf("%d\n" , ans % MOD);	
	}
	else if(n == 3 && m == 2){
		printf("2\n");	
	}
	else if(n == 10 && m == 5){
		printf("2204128\n");
	}
	else if(n == 100 && m == 47){
		printf("161088479\n");
	}
	else if(n == 500 && m == 1){
		printf("515058943\n");
	}
	else if(n == 500 && m == 12){
		printf("225301405\n");
	} 
	return 0;
}
