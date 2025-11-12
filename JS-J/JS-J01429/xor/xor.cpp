#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 10;

int n, k, a[N], ans = 0;
bool b[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		if(b[i]) continue;
		int t = a[i], r = i + 1;
		while(t < k && r < n && !b[r]){
			t ^= a[r];
			r++;
			///if(b[r])  break;
		}
		if(t == k){
			ans++;
			for(int j = i; j < r; j++)
				b[j] = true;
		}
	}
	cout << ans;
}
