#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int n_ans = a[i];
		for(int j = i + 1;j <= n;j++){
			if(n_ans == k){
				ans++;
			}
			n_ans = n_ans ^ a[j];
		}
	}
	cout << ans;
	return 0;
}