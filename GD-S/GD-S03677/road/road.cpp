#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include<queue>
// #define int long long
using namespace std;

int TT = 2;
const int MAXN = 1e4 + 5;
const int MR = 1e6 + 5;
const int MAXM = 10 + 5;
int c[MAXM];
int a[MAXM][MAXN];
struct E{int u,v,w;}e[MR];
bool operator < (const E & a,const E & b){
	return a.w < b.w;
}
int n,m,k;
int fa[MAXN];
int find(int x){return (fa[x] == x? x : fa[x] = find(fa[x]));}
void merge(int x,int y){fa[find(x)] = find(y);}
long long kruskal(){
	long long ans = 0;
	int cnt = 0;
	for(int i = 1;i <= m && cnt < n - 1;i++){
		if(find(e[i].u) == find(e[i].v)) continue;
		ans += e[i].w;
		cnt++;
		merge(e[i].u,e[i].v);
	}
	return ans;
}
int p[MAXN][101];
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	TT = max(2,min(10,20000000 / (((1 << k) + m) * k)));
	for(int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1,e + m + 1);
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			for(int k = 1;k <= TT;k++){
				if(p[i][k] == 0 || a[i][j] <= a[i][p[i][k]]){
					for(int l = TT;l > k;l--) p[i][l] = p[i][l-1];
					p[i][k] = j;
					break;
				}
			}
			// if(fir[i] == 0 || a[i][j] <= a[i][fir[i]]){
				// sec[i] = fir[i];
				// fir[i] = j;
			// }
			// else if(sec[i] == 0 || a[i][j] <= a[i][sec[i]]){
				// sec[i] = j;
			// }
		}
	}
	for(int i = 1;i <= n;i++) fa[i] = i;
	long long ans = 1e18;
	for(int x = 2;x <= TT;x++)
		for(int i = 0;i < (1 << k);i++){
			for(int j = 1;j <= n;j++) fa[j] = j;
			long long sum = 0;
			for(int j = 1;j <= k;j++)
				if(i & (1 << j - 1)){
					sum += a[j][p[j][x]] + c[j];
					for(int mm = 1;mm < x;mm++){
						sum += a[j][p[j][mm]];
						merge(p[j][mm],p[j][mm+1]);
					}
				}
			sum += kruskal();
			// cerr << i << ' ' << sum << '\n';
			ans = min(ans,sum);
		}
	for(int j = 1;j <= n;j++) fa[j] = j;
	cout << min(ans,kruskal());
	return 0;
}