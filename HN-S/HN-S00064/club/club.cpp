#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, a[100005], b[100005], c[100005], ans, e[100005], ca, cb, cc, ce;
struct node{
	int x, y, z;
} d[100005];

bool cmp(int a, int b){
	return a > b;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> t;
	while(t--){
		cin >> n;
		ca = cb = cc = ce = ans = 0;
		for( int i = 1; i <= n; i++ ){
			cin >> d[i].x >> d[i].y >> d[i].z;
			if(d[i].x >= d[i].y && d[i].x >= d[i].z){
				a[++ca] = i;
				ans += d[i].x;
			}
			else if(d[i].y >= d[i].x && d[i].y >= d[i].z){
				b[++cb] = i;
				ans += d[i].y;
			}
			else{
				c[++cc] = i;
				ans += d[i].z;
			}
		}
		if(ca > n / 2){
			ce = ca;
			for( int i = 1; i <= ca; i++ ){
				e[i] = max(d[a[i]].y - d[a[i]].x, d[a[i]].z - d[a[i]].x);
			}
		}
		if(cb > n / 2){
			ce = cb;
			for( int i = 1; i <= cb; i++ ){
				e[i] = max(d[b[i]].x - d[b[i]].y, d[b[i]].z - d[b[i]].y);
			}
		}
		if(cc > n / 2){
			ce = cc;
			for( int i = 1; i <= cc; i++ ){
				e[i] = max(d[c[i]].x - d[c[i]].z, d[c[i]].y - d[c[i]].z);
			}
		}
		sort(e + 1, e + ce + 1, cmp);
		for( int i = 1; i <= ce - n / 2; i++ ) ans += e[i];
		cout << ans << '\n';
	}
	return 0;
}
//只有两个部门
//每个部门各分 n/2 个 
//假设都分给 a
//然后从 a 调剂到 b
//只有三个部门
//假设全部分给 a
//有 n 个二元组 (x, y)
//要选择至少 n/2 个， 
//有一件很显然的事情->
//如果每个分配给最高的
//那么最多只会有一个部门不满足题意
//此时只要将第一个部超出的人全部消掉就可以了 
