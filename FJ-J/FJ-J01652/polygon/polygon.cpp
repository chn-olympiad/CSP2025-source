#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 5005;
const int MOD = 998244353;

int n,a[N],us[N],usmax,busmax;//used-sticks before-used-sticks-maxnum
bool flag[N];
int ans;

int sum(int l) {
	int s = 0;
	for(int i=1; i <= l; i++) {
		s += us[i];
	}
	return s;
}

void dfs(int l,int k) {
	if(k > n) {
		return;
	}
	if(l-1 >= 3) {
		if(sum(l) > usmax*2) {
			ans++;
			ans %= MOD;
		}
	}
	
	for(int i=k; i <= n; i++) {
		if(!flag[i]) {
			us[l] = a[i];
			busmax = usmax;
			usmax = max(usmax,us[l]);
			flag[i] = true;
			dfs(l+1,i);
			flag[i] = false;
			usmax = busmax;
			us[l] = 0;
		}
	}
}

void solve() {
	cin >> n;
	for(int i=1; i <= n; i++) {
		cin >> a[i];
	}
	
	if(n <= 3) {
		if(max(a[1],max(a[2],a[3])) * 2 < a[1]+a[2]+a[3]) {
			cout << 1;
		}
		else cout << 0;
		return;
	}
	
	dfs(1,1);
	cout << ans;
    return;
}

signed main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}
