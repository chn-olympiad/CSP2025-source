#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
const int comp=998244353;

int fcck() {
	cout << 1;
	int run=0,cnt=0;
	for(int i=0;i<n;i++) {
		if(c[i]>run) {
			if(s[i]==1) {
				cnt++;
			} else run++;
		} else run++;
		if(cnt>=m) {
			return 1;
		}
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int ans=0;
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++) {
		cin >> c[i];
	}
	sort(c,c+n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			next_permutation(c,c+n);
			if(fcck()==1) {
				ans++;
				if(ans>=comp) ans-=comp;
			}
		} 
	}
	cout << ans;
	return 0;
}
}

