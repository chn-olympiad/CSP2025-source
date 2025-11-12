	
#include<bits/stdc++.h>
using namespace std;

int n, a[5555], ans = 1, cnt, k;


int ans_sum(int x, int i, int j){
	for(int k = 1; k < i; k++){
		x = x ^ a[j + k];
	}
	return x;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= n - i + 1; j++){
			int sum = ans_sum(a[j], i, j);
			if(sum == k){
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
}

