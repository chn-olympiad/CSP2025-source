#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5;

struct Path {
	int l,r;
};

int arr[N + 5],pre[N + 5];
Path p[N + 5];

bool cmp(const Path &a,const Path &b) {
	if (a.r != b.r) {
		return a.r < b.r;
	}
	return a.r - a.l < b.r - b.l;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,tot = 0;
	cin >> n >> k;
	
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		
		pre[i] = (pre[i - 1] ^ arr[i]);
	}
	
	for (int l = 1;l <= n;l++) {
		for (int r = l;r <= n;r++) {
			if ((pre[r] ^ pre[l - 1]) == k) {
				p[++tot] = {l,r};
				break;
			}
		}
	}
	
	sort(p + 1,p + tot + 1,cmp);
	
	int cnt = 0,r = 0;
	for (int i = 1;i <= tot;i++) {
		if (p[i].l > r) {
			cnt++;
			r = p[i].r;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
