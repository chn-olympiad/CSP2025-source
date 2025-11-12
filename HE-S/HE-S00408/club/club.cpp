#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	int sum = 0;
	int sum_x = 0;
	int sum_y = 0;
	int sum_z = 0;
	int x[5];
	int y[5];
	int z[5];
	cin >> t;
    for(int i = 1; i <= t; i++){
    	int n; 
    	cin >> n;
    	for(int i = 0; i < n; i++){
    		cin >> x[i] >> y[i] >> z[i];
    		int m = max(x[i] , y[i]);
    		int M = max(m, z[i]);
    		if(sum_x <= n / 2){
    			if(M == x[i]){
    			sum_x++;
    			sum+=M;
    			x[i] = 0;
			}
		} 	if(sum_y <= n / 2){
    			if(M == y[i]){
    			sum_y++;
    			sum+=M;
    			y[i] = 0;
			}
		} 	if(sum_z <= n / 2){
    			if(M == z[i]){
    			sum_z++;
    			sum+=M;
    			z[i] = 0;
			}
		} 
	  }
   }
	 
	return 0;
}
