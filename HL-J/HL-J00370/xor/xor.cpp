#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5 * 1e5 + 5;
int n,k,a[maxn],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if(a[i] == 1) sum++;
		}
		cout << sum << endl;
	}else{
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if(a[i] == 1 && a[i+1] == 1){
				sum++;
			}
			if(a[i] == 0){
				sum++;
			}
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
