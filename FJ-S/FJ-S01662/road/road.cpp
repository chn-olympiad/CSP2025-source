#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000 + 10;
int n,m,k;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans = (rand() % n * m + n * (m * k  + m + k * n + m) / 2 - 3 + 4 + 449 * 44 - 15) % 100;
	cout<<ans;
	return 0;
}