#include<bits/stdc++.h>
using namespace std;
long long reach[5010] = {1} , pls[5010] , a[5010];
long long tot = 1 , ans;
const int mod = 998244353;

int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout); 
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i++){
		long long x;
		x = a[i];
		long long sum = 0;
		for(int j = x + 1; j <= 5001; j++){
			sum += reach[j];
			reach[j] %= mod;
			sum %= mod;
		}
		ans += sum;
		ans %= mod;
		for(int j = 0; j <= 5001; j++){
			pls[min(j + x , 5001ll)] += reach[j];
		}
		for(int j = 0; j <= 5001; j++){
			reach[j] += pls[j];
			pls[j] = 0;
		}
	}
	cout << ans;
	return 0;
}