#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
    int n;
    cin >> n;
    long long tmax = 0;
    long long ans = 0;
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
	}
	if(n == 3){
	   for(int i = 1; i <= n; i++){
	   	   ans += a[i];
	   	   if(a[i] > tmax){
	   	   	  tmax = a[i];
			}
	   }
	   if(ans > tmax * 2){
	   	  cout << 1;
	   	  return 0;
	   }else{
	   	  cout << 0;
	   	  return 0;
	   }
	}else if(n == 1 || n == 2){
	   cout << 0;
	   return 0;
	}
	for(int l = 1; l < n; l++){
	   	for(int r = l + 1; r <= n; r++){
	   	   	ans = 0;
	   	   	tmax = 0;
	   	   	for(int i = l; i <= r; i++){
	   	   	   	ans += a[i];
	   	   	   	if(a[i] > tmax){
	   	   	   	   tmax = a[i];
				}
			}
			if(ans > tmax * 2){
			   cnt++;
			}
		} 
	}
	cout << cnt;
	return 0; 
} 
