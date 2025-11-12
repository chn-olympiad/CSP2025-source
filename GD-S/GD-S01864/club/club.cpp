#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
using namespace std;
const int MAX=1e5+10;
int t=1, n, los[MAX], mx;
ll ans;
struct Node{
	int a, b, c;
}arr[MAX];
void init() {
	ans=0;
}
bool cmp(int a, int b) {
	return los[a]>los[b];
}
void exe() {
	vector<int> a, b, c;
	for (int i=1;i<=n;i++) {
		scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
		mx=max({arr[i].a, arr[i].b, arr[i].c});
		if (mx==arr[i].a) {
			los[i]=min(arr[i].a-arr[i].b, arr[i].a-arr[i].c);
			a.push_back(i);
			ans+=arr[i].a;
		}
		else if (mx==arr[i].b) {
			los[i]=min(arr[i].b-arr[i].a, arr[i].b-arr[i].c);
			b.push_back(i);
			ans+=arr[i].b;
		}
		else {
			los[i]=min(arr[i].c-arr[i].b, arr[i].c-arr[i].a);
			c.push_back(i);
			ans+=arr[i].c;
		}
	}
	if (a.size()>n>>1) {
		sort(a.begin(), a.end(), cmp);
		for (int i=n>>1;i<a.size();i++) ans-=los[a[i]];
	}
	else if (b.size()>n>>1) {
		sort(b.begin(), b.end(), cmp);
		for (int i=n>>1;i<b.size();i++) ans-=los[b[i]];
	}
	else if (c.size()>n>>1) {
		sort(c.begin(), c.end(), cmp);
		for (int i=n>>1;i<c.size();i++) ans-=los[c[i]];
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		init();
		exe();
	}
	return 0;
}
