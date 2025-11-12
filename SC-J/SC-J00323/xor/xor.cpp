#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100; 
int n, k;
int a[N];
int xorr(int a,int b){
	return (a|b) - (a&b);
}
int main(){
	freopen("xor.in", "r",stdin);
	freopen("xor.out", "w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cnt = 0;
	int ans;
	for(int i = 1; i <= n; i++){
		ans = a[i];
		if(ans == k){
			cnt++;
			continue;
		}
		for(int j = i + 1; j <= n; j++){
			ans = xorr(ans, a[j]);
			if(ans == k){
				cnt++;
				i = j;
				break;
			}
		}
	}
	cout << cnt;
	return 0;	
}
