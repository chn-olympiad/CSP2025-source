#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
    int a[500001];
    for (int i = 1;i <= n ;i++) cin >> a[i];
    long long sum = 0, ans = 0, r_max = -1;
    for (int l = 1;l <= n;l ++){
    	for (int r = 1;r <= n;r ++){
    		for (int i = l;i <= r;i++){
    			ans = ans ^ a[i];
			}
			if (ans == k){
				if (l > r_max){
					sum ++;
					r_max = r;
				}
			}
			ans = 0;
		}
	}
	cout << sum; 
	return 0; 
}
