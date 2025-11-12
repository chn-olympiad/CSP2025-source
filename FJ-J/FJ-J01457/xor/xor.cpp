#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

const int N = 5e5+5;
int n, k, a[N], ans;

int sumxor(int s, int e){
	int cnt=a[s];
	for(int i=s+1; i<=e; i++){
		cnt ^= a[i];
	}
	return cnt;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	IOS;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int cnt = sumxor(i, j);
			if(cnt == k){
				ans++;
				i = j;
			}
		}
	}
	cout << ans << endl;
	return 0;
}


