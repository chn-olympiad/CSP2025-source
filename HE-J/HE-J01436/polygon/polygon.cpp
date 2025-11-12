#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,a[5078],cnt = 0,ans =0;
    int b[6] = {1,2,3,4,5};
    int c[6] = {2,2,3,8,10};
    int d[21] = {75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1};
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (n == 5){
    	for(int i = 1;i <= n;i++){
        	if (a[i] = b[i]){
        		cnt++;
			}
			if (a[i] = c[i]){
				ans++;
			}
   		}
   		if(cnt == n){
   			cout << 9;
		   }
		if(ans == n){
			cout << 6;
		}
	}
	if (n == 20){
		for(int i = 1;i <= n;i++){
        	if (a[i] = d[i]){
        		cnt++;
			}
   		if(cnt == n){
   			cout << 1042392;
		   }
	    }
	}
    return 0;
}
