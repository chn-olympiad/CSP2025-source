#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,k;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	long long f = 0;
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			f ^= a[j];
			if(f == k){
				ans++;
				i = j;
				break;
			}
		}
		f = 0;
	}
	cout << ans;
	return 0;
}
