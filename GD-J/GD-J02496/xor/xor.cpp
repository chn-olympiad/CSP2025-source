#include <bits/stdc++.h>
using namespace std;
// this is wrong 
// maybe it will be 60 or 40 points
int nums[5000005], listnum[5000005];
vector <int> x;
vector <int> y;
int cmp(int x1, int y1) {
	return y[x1] < y[y1];
}
int defxor(int x, int y) {
	int k = 1, cx = x, cy = y, ans = 0;
	while(x >= k) k *= 2;
	while(y >= k) k *= 2;
	k /= 2;
	while(k != 0) {
		if((cx < k && cy >= k) || (cx >= k && cy < k)) ans+=k;
		if(cx >= k) cx -= k;
		if(cy >= k) cy -= k;
		k /= 2;
	}
	return ans;
}	
void solve(int len) {
	int ty = y[listnum[0]], ans = 1;
	for(int i=1;i<=len;i++) {
		if(x[listnum[i]] > ty) {
			ty = y[listnum[i]];
			ans++;
		}
	}
	cout << ans;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> nums[i];
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			if(i == j) {
				if(nums[i] == k) {
					x.push_back(i);
					y.push_back(j);
					listnum[cnt] = cnt;
					cnt++;
				}
				continue;
			}
			int add = nums[i];
			for(int m=i+1;m<=j;m++) {	
//				cout << i << j << ' ' << add << ' ' << nums[m] << ' ' << ' ' << defxor(add, nums[m]) << endl;
				add = defxor(add, nums[m]);	
			}
//			cout << i << j << ' ' << add << endl;
			if(add == k) {
//				cout << i << j;
				x.push_back(i);
				y.push_back(j);
				listnum[cnt] = cnt;
				cnt++;
			}
		}
	}
	sort(listnum, listnum+cnt+1, cmp);
//	for(int i=0;i<=cnt;i++) {
//		cout << x[listnum[i]] << ' ' << y[listnum[i]] << endl;
//	}
	solve(cnt);
	return 0;
}

