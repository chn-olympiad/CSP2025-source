#include<bits/stdc++.h>
using namespace std;
int a[500];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n , ans = 0;
	cin >> n;
	for(int i = 1; i<= n; i ++){
		cin >> a[i];
	}
	if(n == 4){
		if(a[1]+a[2]+a[3] > max(a[1] , max(a[2] , a[3]))) ans++;
		if(a[1]+a[3]+a[4] > max(a[1] , max(a[4] , a[3]))) ans++;
		if(a[2]+a[3]+a[4] > max(a[2] , max(a[4] , a[3]))) ans++;
		cout << ans;
		
	}else if(n == 5){
		if(a[1]+a[2]+a[3] > max(a[1] , max(a[2] , a[3]))) ans++;
		if(a[1]+a[3]+a[4] > max(a[1] , max(a[4] , a[3]))) ans++;
		if(a[2]+a[3]+a[4] > max(a[2] , max(a[4] , a[3]))) ans++;
		if(a[1]+a[2]+a[3]+a[4] > max(max(a[1],a[2]) , max(a[4] , a[3]))) ans++;
		if(a[1]+a[2]+a[3]+a[5] > max(max(a[1],a[2]) , max(a[3] , a[5]))) ans++;
		if(a[1]+a[2]+a[4]+a[5] > max(max(a[1],a[2]) , max(a[2] , a[4]))) ans++;
		if(a[1]+a[5]+a[3]+a[4] > max(max(a[1],a[4]) , max(a[5] , a[3]))) ans++;
		if(a[5]+a[2]+a[3]+a[4] > max(max(a[5],a[2]) , max(a[2] , a[3]))) ans++;
	}else{
	for(int i = 1; i <= n-2; i ++){
		for(int j = i+2; j <= n; j ++){
			int sum = 0;
			int maxx = INT_MIN;
			for(int l = i; l <= j; l ++){
				sum += a[l];
				if(a[l] > maxx) maxx = a[l]; 
			}
			if(sum > maxx*2){
				cout << sum;
				cout << " ";
				cout << maxx;
				cout << endl;
			}	
		}
	}
	cout << ans;
}
return 0;
}
// 1 2 3 4 5 6
// i 
