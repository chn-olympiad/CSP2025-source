#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

const int N = 5e3+5, MOD = 998244353;
int n, a[N], ans;
string c;
set<string> s;

int sum(int s, int e, int gs, int ge) {
	int cnt=0;
	c = "";
	if(gs == 0 && ge == 0) {
		for(int i=s; i<=e; i++) {
			cnt += a[i];
			c += a[i];
		}
	} else {
		for(int i=s; i<=gs-1; i++) {
			cnt += a[i];
			c += a[i];
		}
		for(int i=ge+1; i<=e; i++) {
			cnt += a[i];
			c += a[i];
		}
	}
	return cnt;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	IOS;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=3; i<=n; i++) {
		int t = sum(1, i-1, 0, 0);
		if(t <= a[i]) {
			continue;
		} else {
			c += i;
			s.insert(c);
		}
		for(int j=1; j<=i-1; j++) {
			for(int k=j+1; k<=i-1; k++) {
				for(int gs=j; gs<=k; gs++) {
					for(int ge=gs; ge<=k; ge++) {
						t = sum(j, k, gs, ge);
						if(t > a[i]) {
							c += i;
							s.insert(c);
						}
					}
				}
			}
		}
	}
	cout << s.size() % MOD << endl;
	return 0;
}

