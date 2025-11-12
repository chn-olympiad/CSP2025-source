#include<bits/stdc++.h>
using namespace std;
int x[500005] , a[500005] , ans = 0 , minb = int(1e9) , maxe = 0;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
		a[i] = a[i - 1] xor x[i];
	} 
	for(int i = 1 , x = 0;i <= n;i++){
		for(int j = x;j <= i;j++){
			if((i >= minb && i <= maxe) && (j >= minb && j <= maxe)) continue;
			int t;
			t = a[i] xor a[j];
			if(t == k) {
				ans++;
				x = i , i++;
			}
		}	
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}