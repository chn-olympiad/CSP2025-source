#include<bits/stdc++.h>
using namespace std;
int n , a[5000005] , k , ans = 0 , bi = 0;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] == k) ans ++;	
	}
	for(int i = 1; i <= n; i ++){
	
		if(a[i] == 0)
		{
			bi = 1;
			break;
		} 
		if(a[i] != 0 && a[i] != 1) 
		{
			bi = 2;
			break;
		}
	}
	if(bi == 2){
		cout << ans ;
		return 0;
	}
	else if(bi == 1){
		if(k != 0 && k != 1){
			cout << 0;
			return 0;
		}
		if(k == 1){
			cout << ans;
			return 0;
		}
		if(k == 0){
			for(int i = 1; i <= n - 1; i ++){
				if(a[i] == 1 && a[i + 1] == 1){
					ans ++;
					i = i + 2;
				}
			}
			cout << ans;
			return 0;
		}
	}
	else{
		if(k == 0) ans = n / 2;
		cout << ans;
	}
	return 0;
}