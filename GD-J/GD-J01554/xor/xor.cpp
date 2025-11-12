#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> v;
int all1, all0;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (a[i]!=1) all0++;
		else all1++;
	}
	if (all1==n&&k==0) {
		cout << all1/2;
		return 0;
	} else if (all1==n&&k==1) {
		cout << n;
		return 0; 
	} else if (all1+all0==n&&k==0) {
		for (int i=2;i<=n;i++) {
			if (a[i]==1&&a[i-1]==1) {
				all0++;
				a[i]=0, a[i-1]=0;
			}
		}
		cout << all0;
		return 0;
	} else if (all1+all0==n&&k==1) {
		cout << all1;
		return 0;
	}
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (a[i]==k) {
			ans++;
			v.push_back(i);
		}
	}
//	int x=1, y=1;
//	for (int i=0;i<v.size();i++) {
//		x=y;
//		y=v[i];
//		
//	}
	cout << ans;
	return 0;
}
