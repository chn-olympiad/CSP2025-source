#include<bits/stdc++.h>
using namespace std;
const int maxn = 500010;
long long n,k,ans = 0,bj = 0;
long long a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++)a[i] ^= a[i - 1];
	for(int i = 1;i <= n;i++){
		for(int j = i;j > bj;j--){
			long long cnt = a[i] ^ a[j - 1];
			if(cnt == k){
				bj = i;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
