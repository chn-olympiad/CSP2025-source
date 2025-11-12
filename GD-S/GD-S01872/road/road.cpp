#include<bits/stdc++.h>
using namespace std;
const long long N = 10005, M = 1000005;
struct node{
	long long u, v, far;
}b[M * 5];
bool cmd(node x, node y){return x.far < y.far;};
long long fa[N + 15], n, m, k, nm, sum, minn, ans, num, ys, c[15];
long long find(long long x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(long long i = 1;i <= m;i++)
		cin >> b[i].u >> b[i].v >> b[i].far;
	for(long long i = 1;i <= k;i++){
		cin >> c[i];
		for(long long j = 1;j <= n;j++){
			b[++m].u = n + i, b[m].v = j;
			cin >> b[m].far;
		}
	}
	minn = 1e18;
	sort(b + 1, b + 1 + m, cmd);
	for(long long i = 0;i <= (1 << k) - 1;i++){
		ans = ys = sum = 0;
		for(long long j = 1;j <= k;j++)
			if((i >> (j - 1)) & 1)
				ans += c[j], ys++;
		for(long long j = 1;j <= n + k;j++)fa[j] = j;
		for(long long j = 1;j <= m;j++){
			if(b[j].u > n && !((i >> (b[j].u - n - 1)) & 1))continue;
			if(b[j].v > n && !((i >> (b[j].v - n - 1)) & 1))continue;
			long long xx = find(b[j].u), yy = find(b[j].v);
			if(xx != yy){
				fa[yy] = xx, ans += b[j].far, sum++;
				if(sum >= n + ys - 1)break;
			}
		}
		minn = min(minn, ans);
	}
	cout << minn;
	return 0;
}
