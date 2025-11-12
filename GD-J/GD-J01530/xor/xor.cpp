#include<bits/stdc++.h>
using namespace std;

int a[500005], ans = 0;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, last = 0;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		int sum = 0;
		for(int j=i; j>last; j--){
			sum ^= a[j];
			if(sum == k){
				last = i;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
