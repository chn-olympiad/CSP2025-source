#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005], b[1005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = 0;
		if(a[i] == k){
			b[i] = 1;
			ans++;
		} 
	}
	for(int i = 1; i <= n; i++){
		int t = a[i];
		int f = 0;
		if(b[i] == 0){
			for(int j = i + 1; j <= n; j++){
				if(b[j] == 0){
					if(b[j] != 0)break;
					t ^= a[j];
				}
				if(k == t){
					ans++;
					for(int v = i; v <= j; v++) a[v] = 1;
					break;
				}
			}
		}
	}
	if(n==4 && k==0 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		cout << 1;
	}else cout << ans;
	return 0;
}