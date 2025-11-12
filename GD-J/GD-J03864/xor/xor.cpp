#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k, a[N], b[N], cnt, pos;
struct node{
	int l, r;
}s[N];
bool cmp(node a, node b){
	return a.r < b.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	b[1] = a[1];
	for (int i = 2; i <= n; i++) b[i] = b[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if ((b[j] | b[i]) == k){
				s[++pos].l = i;
				s[pos].r = j;
			}
		}
	}
	sort(s + 1, s + pos + 1, cmp);
	int cur = 0;
	for (int i = 1; i <= pos; i++){
		if (s[i].l > s[cur].r){
			cur = i;
			cnt++;
		} 
	}
	cout << cnt;
	return 0;
}
