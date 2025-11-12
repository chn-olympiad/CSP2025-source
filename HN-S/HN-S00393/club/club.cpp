#include <bits/stdc++.h>
using namespace std;
struct qwqDat {
	int arr[5];
	bool operator<(const qwqDat b) const {
		int tmp1[3] = {arr[1],arr[2],arr[3]};
		int tmp2[3] = {b.arr[1],b.arr[2],b.arr[3]};
		sort(tmp1,tmp1 + 3);
		sort(tmp2,tmp2 + 3);
		return tmp1[2] - tmp1[1] < tmp2[2] - tmp2[1];
	}
};
int n;
qwqDat a[100005];
inline int qwqmax(int k) {
	int res = 0;
	for(int i = 1;i <= 3;i++) if(a[k].arr[res] < a[k].arr[i]) res = i;
	return res;
}
inline int qwqsubmax(int k) {
	int mx = qwqmax(k);
	int tmp = a[k].arr[mx];
	a[k].arr[mx] = -1;
	int ans = qwqmax(k);
	a[k].arr[mx] = tmp;
	return ans;
}
void solve() {
	cin >> n;
	int tmp[4] = {0,0,0,0};
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].arr[1] >> a[i].arr[2] >> a[i].arr[3];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) {
		++tmp[qwqmax(i)];
		ans += a[i].arr[qwqmax(i)];
	}
	int miao = 0;
	for(int i = 1;i <= 3;i++) if(tmp[i] > n / 2) miao = i;
	if(miao == 0) {
		cout << ans << "\n";
		return;
	}
	for(int i = 1;i <= n && tmp[miao] > n / 2;i++) {
		if(qwqmax(i) != miao) continue;
		--tmp[miao];
		ans -= (a[i].arr[qwqmax(i)] - a[i].arr[qwqsubmax(i)]);
	}
	cout << ans << "\n";
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve(); 
	return 0; 
} 
