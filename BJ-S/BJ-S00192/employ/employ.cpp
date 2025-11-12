//AFOing
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Mod 998244353
using namespace std;
int a[510],n,m,d[510];
string s;
int main(void) {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=n;i++) cin >> d[i];
	for (int i=1;i<=n;i++) a[i]=i;
	int ans=0;
	for (;;) {
		bool is=0;
		for (int i=1;i<=n;i++)
			if (a[i]!=n-i+1) is=1;
//		for (int i=1;i<=n;i++) cout << a[i] << " ";
		next_permutation(a+1,a+1+n);
		int v=0;
		for (int i=1;i<=n;i++) {
			if (v>=d[a[i]]||s[i-1]=='0') {
				v++;
			}
		}
//		cout << n-v << endl;
		if (v<=n-m) {
			ans++;
		}
		if (is==0) break;
	}
	cout << ans;
	return 0;
}
