#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
long long a[MAXN];
long long tree[MAXN];
void er_tree(int node, int s, int t){
	if(s == t){
		a[s] = tree[node];
		return;
	}
	int mid = (s + t) / 2;
	a[node] = er_tree(2 * node, s, mid) ^ er_tree(2 * node, mid + 1, t);
}
int find(int node, int s, int t, int l, int r){
	if(l >= s && t <= r){
		return a[node];
	}
	int mid = (s + t) / 2;
	if(l >= mid) return find(2 * node + 1, mid + 1, t, l, r);
	if(r <= mid) return find(2 * node, s, mid, l, r);
	return a[node];
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	er_tree(1, 1, n);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int ans = find(1, 1, n, i, j);
			if(ans == k) cnt++;
		}
	}
	printf("%d", cnt);
    return 0;
}
