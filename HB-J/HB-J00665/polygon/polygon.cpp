#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int l[5005];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> N;
	long long ans = 0;
	for(int i = 1;i <= N;i ++) {
		cin >> l[i];
		ans += l[i];
	}
	
	cout << ans / 998244353;
	// i even don't have any idea.
	return 0;
}
