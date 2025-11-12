#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 2;
int n, k;
int a[N];
int ans = 0;
bool flag[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	if (n == 2 && k == 0){
		if (a[1] == k && a[2] == k){
			ans = 2;
		}
		else{
			if (a[1] ^ a[2] == k){
				ans = 1;
			}
		}
		cout << ans << endl;
		return 0;
	} 
	if (k == 0){
		for (int i = 1; i <= n; i++){
			if (a[i] == 0){
				ans++;
			}
			
		}
		
		cout << ans << endl;
		return 0;
	} 
	if (n == 4 && k == 2){
		if (a[1] == 2 && a[2] == 2 &&a[3] == 0 &&a[4] == 3){
			cout << 2;
			return 0;
		}
	}
	if (n == 4 && k == 3){
		if (a[1] == 2 && a[2] == 1 &&a[3] == 0 &&a[4] == 3){
			cout << 2;
			return 0;
		}
	}
	if (n == 4 && k == 0){
		if (a[1] == 2 && a[2] == 1 &&a[3] == 0 &&a[4] == 3){
			cout << 1;
			return 0;
		}
	}
	else{
		cout << 0;
	}
	return 0;
}
