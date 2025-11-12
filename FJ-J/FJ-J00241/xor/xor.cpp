#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], h = 0, ml, mr, ans = 1;
struct node{
	int l, r;
}q[500005];
bool cmp(node a, node b){
	int al = a.r - a.l;
	int bl = b.r - b.l;
	if(al == bl)return a.l < b.l;
	return al < bl;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] == k)q[++h] = {i, i};
	}
	for(int i = 1; i < n; i++){
		int s = a[i];
		for(int l = 1; l + i <= n; l++){
			int j = i + l;
			s ^= a[j];
			if(s == k)q[++h] = {i, j};
		}
	}
	if(h < 1){
		printf("0\n");
		return 0;
	}
	sort(q + 1, q + 1 + h, cmp);
	for(int m = 1; m <= h; m++){
		ml = q[m].l;
		int sum = 1;
		mr = q[m].r;
		for(int i = 1; i <= h; i++){
			if(q[i].r < ml){
				sum++;
				ml = q[i].l;
			}else if(q[i].l > mr){
				sum++;
				mr = q[i].r;
			}
		}
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}

