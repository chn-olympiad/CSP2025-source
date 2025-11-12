#include<bits/stdc++.h>
using namespace std;

bool flag[10000001];
int n, k, cnt, ans;
int a[1000001];

int main(){
	freopen("xor.out", "r", stdin);
	freopen("xor.in", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n ;i++){
		cin >> a[i];
		if(a[i] == 1) cnt++;
	} 
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			ans++;
		}
	} 
	if(cnt == n && k == 0) cout << n / 2;
	else cout << ans;
	return 0;
} 
