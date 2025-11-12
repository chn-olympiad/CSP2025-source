#include <bits/stdc++.h>
using namespace std;

struct node {
	int l,r,size;
};

bool cmp(node a,node b) {
	return a.size < b.size;
}

int n;
long long k,a[500005];
vector <node> ns;

bool visit[500005];
long long ans;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		int cnt = 0;
		for (int j = i;j <= n;j++) {
			cnt ^= a[j];
			if (cnt == k) {
				node t;
				t.l = i;
				t.r = j;
				t.size = j - i + 1;
				ns.push_back(t);
			}
		}
	}
	int ssss = ns.size();
	node ss[ssss];
	for (int i = 0;i < ssss;i++) ss[i] = ns[i];
	sort(ss,ss + 0 + ns.size(),cmp);
	for (int i = 0;i < ssss;i++) {
		bool f = 0;
		for (int j = ss[i].l;j <= ss[i].r;j++) {
			if (visit[j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) continue;
		ans++;
		for (int j = ss[i].l;j <= ss[i].r;j++) {
			visit[j] = 1;
		}
	}
	cout << ans;
	return 0;
}
