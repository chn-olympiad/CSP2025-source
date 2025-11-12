#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n,k,a[N],cnt;

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i],cnt += (a[i] == 1 ? 1 : 0);
	if (k == 0 && cnt == n){
		cout << n / 2 << endl;
		return 0;
	}
	if (k == 1){
		cout << cnt << endl;
		return 0;
	}
	if (k == 0){
		int c = 1,ans = n - cnt;
		vector<int> s;
		for (int i = 1;i <= n;i++){
			if (a[i] == 0) continue;
			if (a[i] == 1 && a[i+1] == 1) c++;
			else{
				s.push_back(c);
				c = 1;
			}
		}
		for (int x : s) ans += x / 2;
		cout << ans << endl;
	}

	return 0;
}
