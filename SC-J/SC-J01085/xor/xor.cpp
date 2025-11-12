#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 5e5+5;

int n,k;
int a[MAXN];

bool check_A() {
	for (int i=1;i<=n;i++) if (a[i] != 1) return 0;
	return 1;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if (check_A()) {
		cout<<n/2;
	}
	return 0;
} 