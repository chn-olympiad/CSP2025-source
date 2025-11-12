#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k, cnt, ans, lst, a[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	// freeopen("xor.in", "r", stdin);
	// freeopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		cnt = 0;
		for(int j = i;j <= n;j++){
			cnt ^= a[j];
			if(cnt == k && i > lst){
				ans++;
				lst = j;
			}
		}
	}
	cout << ans << endl;
	return 0; 
}
