#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct node{
	long long val;
	int id;
}sum[N];
int n, k, a[N], f[N], tree[4*N];
long long sum2[N];
void update(int now, int L, int R, int pos, int val) {
	if(L > R || pos < L || pos > R) return ;
	if(L == R) {
		tree[now] = max(tree[now], val);
		return ;
	}
	int mid = (L + R) / 2, ls = now * 2, rs = ls + 1;
	update(ls, L, mid, pos, val);
	update(rs, mid + 1, R, pos, val);
	tree[now] = max(tree[ls], tree[rs]);
}
int ask(int now, int L, int R, int x, int y) {
	if(x > R || y < L) return 0;
	if(x <= L && R <= y) return tree[now];
	int mid = (L + R) / 2, ls = now * 2, rs = ls + 1;
	return max(ask(ls, L, mid, x, y), ask(rs, mid + 1, R, x, y));
}
int find(int i, long long x) {
	if(x < sum[1].val) return -1;
	int L = 1, R = n + 1;
	while(L + 1 < R) {
		int mid = (L + R) / 2;
		if(sum[mid].val < x) L = mid;
		else R = mid;
	}
	if(sum[L].val < x) L++;
	while(sum[L].val == x && sum[L].id < i) L++;
	if(sum[L-1].val == x) return sum[L-1].id;
	return -1;                                                                       
}
void solve1()
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == k) {
			f[i] = ask(1, 1, n, 1, i - 1) + 1;
			update(1, 1, n, i, f[i]);
			continue;
		}                 
		int j = find(i, (sum2[i] ^ k));
		if(j != -1) {
			f[i] = ask(1, 1, n, 1, j) + 1;
			update(1, 1, n, i, f[i]);
		}
		else if(sum2[i] == k) {
			f[i] = 1;
			update(1, 1, n, i, f[i]);
		}
	}
	printf("%d", tree[1]);
}
bool cmp(node x, node y) {
	if(x.val == y.val) return x.id < y.id;
	return x.val < y.val;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
		
	sum[1].id = 1, sum[1].val = a[1];
	sum2[1] = a[1];
	for(int i = 2; i <= n; i++)
		sum[i].id = i, sum[i].val = (sum[i-1].val ^ a[i]), sum2[i] = (sum2[i-1] ^ a[i]);
	sort(sum+1, sum+n+1, cmp);
	sum[n+1].val = 1e18;
		
	solve1();
	return 0;
}
