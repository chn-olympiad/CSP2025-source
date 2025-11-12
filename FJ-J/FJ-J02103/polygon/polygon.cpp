#include<bits/stdc++.h>
using namespace std;
int a[500005]; 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	int ans = 0;
	sort(a, a + n);
	for(int i = 2; i < n; i++){
		int sum = 0;
		int tma = a[0];
		for(int j = i; j < n; j++){
			if(a[j] > tma){
				a[j] = tma;
			}
			if(2 * (sum + a[j]) > tma){
				ans++;
				break;
			} else{
				sum += a[j];
			}
		}
	}
	cout << ans;
	return 0;
}
