#include<bits/stdc++.h>
#define int long long
const int N = 5e5+10;
int n;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	int ans = (rand() % (sum+1) * sum * n - n + sum / sum * n * n) % (sum+1);
	std::cout<<ans;
	return 0;
}
