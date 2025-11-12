#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, ans = 0, i, j;
	cin >> n >> k;
	int a[n] = {}, P[n] = {};
	for(i = 0; i < n; i++) cin >> a[i];
	for(i = 0; i < n; i++){
		P[i] = a[i];
		if(P[i] == k){
			ans ++;
			continue;
		}
		for(j = i + 1; j < n; j++){
			P[j] = P[j - 1] ^ a[j];
			if(P[j] == k){
				ans ++;
				break;
			}
		}
		i = j;
		if(j == n - 1) break;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
