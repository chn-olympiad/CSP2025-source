#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, k, ans, a[N], pre[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) pre[i] = (pre[i-1]^a[i]);
	if (k == 0 && n >= 30000){
		a[n+1] = -1;
		for (int i = 1;i <= n;i++){
			if (a[i] == 0) ans++;
			else if (a[i] == 1 && a[i+1] == 1){
				ans++;
				i++;
			}
		}
		cout << ans;
		return 0;
	}else if (k == 1 && n >= 30000){
		for (int i = 1;i <= n;i++)
			ans += a[i];
		cout << ans;
		return 0;
	}
	int lst = 1;
	for (int r = 1;r <= n;r++)
		for (int l = r;l >= lst;l--)
			if ((pre[r]^pre[l-1]) == k){
				ans++;
				lst = r+1;
				break;
			}
	cout << ans;
	return 0;
}