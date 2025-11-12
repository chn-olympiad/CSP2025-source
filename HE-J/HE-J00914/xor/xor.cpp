//rp++
#include<bits/stdc++.h>
using namespace std;
int n , ans;
bool flag[500010] , b = true;
long long k , a[500010] , c[500010];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%d%lld" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		long long t;
		scanf("%lld" , &t);
		a[i] = a[i - 1] ^ t;
		c[i] = t;
		if(t > 1)
			b = false;
	}
	if(b && k <= 1){
		if(k == 0){
			for(int i = 1 ; i <= n ; ++i){
				if(c[i] == 0)
					ans += 1;
				if(c[i] == 1 && c[i + 1] == 1)
					ans += 1 , i += 1;
			}
			printf("%d" , ans);
		}
		else{
			for(int i = 1 ; i <= n ; ++i)
				if(c[i] == 1)
					ans += 1;
			printf("%d" , ans);
		}
		return 0;
	}
	
	//for(int i = 1 ; i <= n ; ++i)
	//	printf("%d " , a[i]);
	//printf("\n");
	
	for(int i = 1 ; i <= n ; ++i){
		if(flag[i])
			continue;
  		for(int j = 1 ; j <= n - i + 1 ; ++j){
			int b = true;
			for(int l = j ; l <= j + i - 1 ; ++l){
				if(flag[l]){
					b = false;
					break;
				}
 			}
			if(!b)
				continue;
			long long num = a[j - 1] ^ a[j + i - 1];
			//printf("The {%d %d} xor is %lld\n" , j , j + i - 1 , num);
			if(num == k){
				ans += 1;
				for(int l = j ; l <= j + i - 1 ; ++l)
					flag[l] = true;
				//printf("The {%d %d} is OK\n" , j , j + i - 1);
			}
		}
	}
	printf("%d" , ans);
	return 0;
}
