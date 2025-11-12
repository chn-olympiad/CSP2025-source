#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll ans; int a[maxn][4];
int b[maxn >> 1], c[maxn >> 1], d[maxn >> 1];
bool cmp1(int x, int y){return (a[x][2] - a[x][1] > a[y][2] - a[y][1]);}
bool cmp2(int x, int y){return (a[x][1] - a[x][2] > a[y][1] - a[y][2]);}
bool cmp3(int x, int y){return (a[x][3] - a[x][1] > a[y][3] - a[y][1]);}
bool cmp4(int x, int y){return (a[x][3] - a[x][2] > a[y][3] - a[y][2]);}
int main(){
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	int t, n; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0; b[0] = c[0] = d[0] = n>>1;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if(i <= b[0]) b[i] = i;
			else c[i - c[0]] = i;
		}sort(b + 1, b + b[0] + 1, cmp1);
		sort(c + 1, c + c[0] + 1, cmp2);
		for(int i = 1; i <= b[0]; i++){
			if(a[b[i]][2] - a[b[i]][1] + a[c[i]][1] - a[c[i]][2] > 0)
				swap(b[i], c[i]);
			else break;
		}sort(b + 1, b + b[0] + 1, cmp3);
		sort(c + 1, c + c[0] + 1, cmp4);
		int l = 1, r = 1, cnt = 0, tmp1, tmp2;
		while(cnt < d[0]){
			tmp1 = a[b[l]][3] - a[b[l]][1];
			tmp2 = a[c[r]][3] - a[c[r]][2];
			if(l <= b[0] && tmp1 > 0){
				if(r <= c[0] && tmp2 > 0){
					if(tmp1 > tmp2) d[++cnt] = b[l++];
					else d[++cnt] = c[r++];
				}else d[++cnt] = b[l++];
			}else if(r <= c[0] && tmp2 > 0) d[++cnt] = c[r++];
			//else break;
		}
		for(; l <= b[0]; l++) ans += a[b[l]][1];//printf("%d ", b[l]); cout << endl;
		for(; r <= c[0]; r++) ans += a[c[r]][2]; //printf("%d ", c[r]); cout << endl;
		for(; cnt >= 1; cnt--) ans += a[d[cnt]][3]; //printf("%d ", d[cnt]); cout << endl;
		printf("%lld\n", ans);
	}
	return 0;
}
