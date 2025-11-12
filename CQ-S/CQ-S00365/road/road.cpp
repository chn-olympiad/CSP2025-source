#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20, M = 2e5 + 10, P = 1e6 + 10;
int n, m, k, tot, c[N], f[N];
long long ans;
struct node{
	int x, y, z;
}a[P], b[M];
inline bool cmp(node u, node v){
	return u.z < v.z;
}
inline int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i = -~i) cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i = 1;i <= k;i = -~i){
		cin>>c[i];
		for(int j = 1;j <= n;j = -~j) b[++tot] = node{i + n, j, 0}, cin>>b[tot].z;
	}
	for(int i = 1;i <= n;i = -~i) f[i] = i;
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1;i <= m;i = -~i){
		int x = find(a[i].x), y = find(a[i].y);
		if(x != y) b[++tot] = a[i], f[x] = y;
	}
	sort(b + 1, b + 1 + tot, cmp);
	for(int i = 0;i < (1 << k);i = -~i){
		long long sum = 0, cnt = n - 1;
		for(int j = 1;j <= k;j = -~j) if((i >> (j - 1)) & 1) sum += c[j], cnt ++;
		for(int j = 1;j <= n + k;j = -~j) f[j] = j;
		for(int j = 1;j <= tot && cnt;j = -~j){
			if(b[j].x > n && !((i >> (b[j].x - n - 1)) & 1)) continue;
			int x = find(b[j].x), y = find(b[j].y);
			if(x != y) sum += b[j].z, f[x] = y, cnt --;
		}
		if(i == 0 || ans > sum) ans = sum;
	}
	cout<<ans;
	return 0;
}
