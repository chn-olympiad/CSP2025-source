#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
struct node {
	int x, y, z;
} a[1000010];
bool cmp1(node c, node d) {
	return c.x - max(c.y, c.z) < d.x - max(d.y, d.z);
}
bool cmp2(node c, node d) {
	return c.y - max(c.x, c.z) < d.y - max(d.x, d.z);
}
bool cmp3(node c, node d) {
	return c.z - max(c.x, c.y) < d.z - max(d.x, d.y);
}
vector<node> v1, v2, v3;
int T, n;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
			if(a[i].x >= a[i].y && a[i].x >= a[i].z) cnt1++, sum += a[i].x, v1.push_back(a[i]);
			else if(a[i].y >= a[i].x && a[i].y >= a[i].z) cnt2++, sum += a[i].y, v2.push_back(a[i]);
			else cnt3++, sum += a[i].z, v3.push_back(a[i]);
		}
		if(cnt1 > n / 2) {
			sort(v1.begin(), v1.end(), cmp1);
			for(int i = 0; cnt1 > n / 2; i++) {
				sum = sum - v1[i].x + max(v1[i].y, v1[i].z); cnt1--;
			}
			printf("%lld\n", sum);
		}
		else if(cnt2 > n / 2) {
			sort(v2.begin(), v2.end(), cmp2);
			for(int i = 0; cnt2 > n / 2; i++) {
				sum = sum - v2[i].y + max(v2[i].x, v2[i].z); cnt2--;
			}
			printf("%lld\n", sum);
		}
		else if(cnt3 > n / 2) {
			sort(v3.begin(), v3.end(), cmp3);
			for(int i = 0; cnt3 > n / 2; i++) {
				sum = sum - v3[i].z + max(v3[i].x, v3[i].y); cnt3--;
			}
			printf("%lld\n", sum);
		}
		else printf("%lld\n", sum);
		v1.clear(), v2.clear(), v3.clear();
	}
	return 0;
}
