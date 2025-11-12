#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	int arr[n], sum[n], len[n];
	memset(len, 0, sizeof(len));
	
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		if(i == 0) sum[0] = arr[0];
		else{
			sum[i] = arr[i] ^ sum[i-1];
		}
	}
	
	int add;
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			add = sum[j];
			if(i != 0) add ^= sum[i-1];
			if(add == k){
				len[i] = min(len[i], j-i+1);
				if(len[i] == 0) len[i] = j-i+1;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(len[i] > 0){
			ans++;
			i += len[i]-1;
		}
	}
	
	cout << ans;
	return 0;
}
