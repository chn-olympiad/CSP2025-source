#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 500010;
int a[N];
vector<pair<int,int>> vec;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
    	cin >> a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			int x = 0;
			for(int K=i;K<=j;K++) {
				x ^= a[K];
			}
			if(x == k) {
				vec.push_back({i,j});
			}
		}
	}
	int len = vec.size() - 1;
	vector<int> f(len + 10);
	f[0] = 1;
	for(int i=1;i<=len;i++) {
		f[i] = f[i-1];
		for(int j=0;j<i;j++) {
			if(vec[j].second < vec[i].first) {
				f[i] = max(f[i],f[j] + 1);
			}
		}
	}
	cout << f[len];
	return 0;
}