#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n,k,lst,cnt;
int a[N],pre[N];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	mp[0] = 1;lst = 1;
	for (int i = 2;i <= n + 1;i++) cin >> a[i];
	for (int i = 2;i <= n + 1;i++){
		pre[i] = pre[i - 1] ^ a[i];
		if (mp[pre[i] ^ k] >= lst) cnt++,lst = i;
		mp[pre[i]] = i;
//		cout << i << " " << cnt << " " << pre[i] << " " << (pre[i] ^ k) << " " << mp[pre[i] ^ k] << " " << mp[pre[i]] << "\n";
	}cout << cnt << "\n";
	return 0;
}
