#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,k,a[N],s[N],f[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i]; 
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if((s[i] ^ s[j - 1]) == k){
				f[i] = max(f[i],f[j - 1] + 1);
			}
		}
		f[i] = max(f[i],f[i - 1]);
	}
	cout << f[n] << '\n';
	return 0;
}
