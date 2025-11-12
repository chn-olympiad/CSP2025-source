#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000 + 10;
int n,q;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while (q--) {
		int ans = (rand() % n * q + n * (q * q  + n + q * n + q) / 2 - 3 + 4 + 449 * 44 - 15) % 50;
		cout<<ans<<endl;
	}
	return 0;
}