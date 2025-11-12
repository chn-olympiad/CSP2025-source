#include<bits/stdc++.h>
using namespace std;
int n , a[5005] , ps[5005] , ans ;
void f (int x , int p , int s , int c){
	if(c == p){
		if(s > 2 * a[x]) ans = ans % 998244353 + 1;
	}
	for(int i = x + 1 ; i <= n ; i++){
		f(i , p , s + a[i] , c + 1);
	} 
}
int js(int a , int b){
	int ans1 = 1;
	for(int i = 1 ; i <= b ; i++){
		ans1 *= (a - i + 1);
		ans1 /= i;
		ans1 %= 998244353;
	}
	return ans1;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	if(a[n] != 1){
		for(int i = 3 ; i <= n ; i++){
			for(int j = 1 ; j + i - 1 <= n ; j++){
				f(j , i , a[j] , 1);
			}
		}
	}else{
		for(int i = 3 ; i <= n ; i++){
			ans = (ans % 998244353 + js(n , i) % 998244353) % 998244353; 
		}
	}
	cout << ans;
	return 0;
}

