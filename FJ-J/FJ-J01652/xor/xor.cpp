#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 5e5+5,M = 1e3+5;
const int MOD = 10;

int n,k,a[N],f[M][M];
int ans;

int xor_sum(int l,int r) {
	int ans = a[l];
	for(int i=l+1; i <= r; i++) {
		ans ^= a[i];
	}
	return ans;
}

void pre() {
	for(int i=1; i <= n; i++) {
		for(int j=i; j <= n; j++) {
			f[i][j] = xor_sum(i,j);
		}
	}
	return;
}

void k0ans() {
	if(n%2==0) cout << n/2;
	else cout << n/2-1;
	return;
}

void dfs(int l,int r) {
	int answer = 0;
	if(l > n) {
		return;
	}
	
	for(int i=l; i <= n; i++) {
		for(int j=r; j <= n; j++) {
			if(f[i][j] == k) {
				answer++;
				dfs(j+1,j+1);
			}
		}
	}
	
	ans = max(ans,answer);
	return;
}

void solve() {
	cin >> n >> k;
	for(int i=1; i <= n; i++) {
		cin >> a[i];
	}
	
	if(k == 0) k0ans();return;
	pre();
	dfs(1,1);
	cout << ans;
    return;
}

signed main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}
