#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in", "r",stdin);
	freopen("club.out","w",stdout);
	int n , d ,a[10005][3],max;
	cin >> n;
	if (n%2==0&&d != 2/n){
		for(int i = 1;i <= n;i++){
	        for(int j = 1;j <= 3;j++){
	    	    cin >> a[i][j];
		    } 
		}		
	    for(int i = 1;i <= n;i++){
	    	for(int j = 1;j <= 3;j++){
			     cout << a[i][j];
	    		cout << max;
			}
		}
	}	
	return 0;
}

