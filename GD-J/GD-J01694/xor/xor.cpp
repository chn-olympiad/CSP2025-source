#include<bits/stdc++.h>
using namespace std;
long long n, k; 
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int x;
		if(a[i] == k){
			ans++;
			continue; 
		}
		for(int j = 1;j <= i; j++){
			x = a[i] xor a[j];
			if(x == k){
				ans++;
				continue;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
