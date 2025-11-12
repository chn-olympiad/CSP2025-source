#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , a[2000005] , b[2000005] , ans = 0;
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i]; 
	}
	sort(a + 1 , a + 1 + n);
	b[0] = 0;
	for(int i = 1; i <= n; i ++){
		b[i] = a[i];
		b[i] += b[i - 1];
	}
	for(int k = 1; k <= n - 3 + 1; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] > a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 3){
		cout << ans;
		return 0;
	}
	for(int kh = 1; kh <= n - 4 + 1; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] + a[kh]> a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 4){
		cout << ans;
		return 0;
	}	
	for(int kk = 1; kk <= n - 5 + 1; kk ++)		
	for(int kh = kk + 1; kh <= n; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] + a[kh] + a[kk]> a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 5){
		cout << ans;
		return 0;
	}
	for(int ka = 1; ka <= n - 6 + 1; ka ++)
	for(int kk = ka + 1; kk <= n; kk ++)		
	for(int kh = kk + 1; kh <= n; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] + a[kh] + a[kk] + a[ka]> a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 6){
		cout << ans;
		return 0;
	}		
	for(int kb = 1; kb <= n - 6; kb ++)
	for(int ka = kb + 1; ka <= n; ka ++)
	for(int kk = ka + 1; kk <= n; kk ++)		
	for(int kh = kk + 1; kh <= n; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] + a[kh] + a[kk] + a[ka] + a[kb] > a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 7){
		cout << ans;
		return 0;
	}
	for(int kc = 1; kc <= n - 7; kc ++)
	for(int kb = kc + 1; kb <= n; kb ++)
	for(int ka = kb + 1; ka <= n; ka ++)
	for(int kk = ka + 1; kk <= n; kk ++)		
	for(int kh = kk + 1; kh <= n; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] + a[kh] + a[kk] + a[ka] + a[kb] + a[kc]> a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 8){
		cout << ans;
		return 0;
	}
	for(int kd = 1; kd <= n - 8; kd ++)
	for(int kc = kd + 1; kc <= n; kc ++)
	for(int kb = kc + 1; kb <= n; kb ++)
	for(int ka = kb + 1; ka <= n; ka ++)
	for(int kk = ka + 1; kk <= n; kk ++)		
	for(int kh = kk + 1; kh <= n; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[k] + a[j] + a[i] + a[kh] + a[kk] + a[ka] + a[kb] + a[kc] + a[kd]> a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 9){
		cout << ans;
		return 0;
	}		
	for(int ke = 1; ke <= n - 9; ke ++)
	for(int kd = ke + 1; kd <= n; kd ++)
	for(int kc = kd + 1; kc <= n; kc ++)
	for(int kb = kc + 1; kb <= n; kb ++)
	for(int ka = kb + 1; ka <= n; ka ++)
	for(int kk = ka + 1; kk <= n; kk ++)		
	for(int kh = kk + 1; kh <= n; kh ++)
	for(int k = kh + 1; k <= n; k ++)
		for(int j = k + 1; j <= n; j ++)
			for(int i = j + 1; i <= n; i ++){
				if(a[ke] + a[k] + a[j] + a[i] + a[kh] + a[kk] + a[ka] + a[kb] + a[kc] + a[kd]> a[i]*2){
					ans ++;
					//cout<<a[k] + a[j] + a[i]<<" "<<a[i]*2<<endl;
				} 
			}
	if(n == 10){
		cout << ans;
		return 0;
	}		
	return 0;
} 