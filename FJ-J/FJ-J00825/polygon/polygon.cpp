#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int N2=1e7+5;
int a[N], ha[N2];

int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << 0;
		return 0;
	} else if(n == 2) {
		int k=max(a[1],a[2]);
		if(a[1]+a[2] > k*2) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	} else if(n == 3) {
		int ans=0;
		int u=a[1]+a[2];
		int p=a[2]+a[3];
		int o=a[1]+a[3];
		int umax1=max(a[1],a[2]);
		int pmax1=max(a[2],a[3]);
		int omax1=max(a[1],a[3]);
		if(u > umax1*2) {
			ans++;
		}
		if(p > pmax1*2) {
			ans++;
		}
		if(o > omax1*2) {
			ans++;
		}
		cout << ans;
		return 0;
	} else {
		int cnt=1;
		ha[1] = a[1];
		long long ans2=0;
		for(int i=2; i<=n; i++) {
			int cnt1=1;
			for(int j=1; j<=cnt; j++) {
				if(j == 1) {
					ha[cnt+1] = a[i];
				}
				if(ha[j]+a[i] > a[i]*2) {
					ans2 ++;
				}
					cnt1 += 1;
					ha[cnt+cnt1] = ha[j]+a[i];
			}
			cnt += cnt1;
			ans2%=998244353;
		}
		cout << ans2;
	}

	return 0;
}
