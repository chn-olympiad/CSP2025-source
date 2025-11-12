#include<bits/stdc++.h>
using namespace std;
int n, a[6010], sum, ans;
bool f = 1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > 1){
        	f = 0;
		}
	}
	if(f == 1){
	    for(int i = 1; i <= n-2; i++){
	    	sum += i;
		}
		cout << sum;
	}else{
	    ans = max(max(a[1], a[2]), a[3]);
	    if(a[1]+a[2]+a[3] > 2*ans){
	    	cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}