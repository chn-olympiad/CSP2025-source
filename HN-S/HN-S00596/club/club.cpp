#include <bits/stdc++.h>
using namespace std;
int t;
struct node{
	int z,x,c;
};
bool cmp(node a, node b) {
	return a.z > b.z;
}
bool cmp1(node a, node b) {
	return a.x > b.x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		node a[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].z>>a[i].x>>a[i].c;
		}
		bool f = true;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (a[i].x != 0 || a[i].c != 0) {
				f = false;
			}
			if (a[i].c != 0) flag = false;
		}
		if (f) {
			int ans =0;
			sort (a + 1, a + 1 + n, cmp);
			for (int i = 1; i <= n/ 2; i++) {
				ans += a[i].z;
			}
			cout << ans;
		} else if (flag) {
			sort (a + 1, a + 1 + n, cmp);
			int ans= 0;
			for (int i = 1; i <= n/2;i++) {
				ans += a[i].z;
			} 
			for (int j = n / 2 + 1; j <= n; j++) {
				ans += a[j].x;
			}
			int sum = 0;
			sort (a + 1, a + 1 + n, cmp1);
			for (int i = 1; i <= n/2;i++) {
				sum += a[i].x;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				sum += a[i].z;
			}
			cout << max(ans, sum) << endl;
		}
	}
	return 0;
}
