#include <bits/stdc++.h>
using namespace std;
struct node{
	int a, b, c;
}w[100005];
struct nodea{
	int gx;
	int fang;
	int ren;
}jisuan[300015];
int vis[100005];
bool cmp(nodea diyi, nodea dier){
	return diyi.gx > dier.gx;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		memset(w, 0, sizeof(w));
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
			jisuan[(i - 1) * 3 + 1].fang = 1;
			jisuan[(i - 1) * 3 + 1].gx = (w[i].a - max(w[i].b, w[i].c));
			jisuan[(i - 1) * 3 + 1].ren = i;
			jisuan[(i - 1) * 3 + 2].fang = 2;
			jisuan[(i - 1) * 3 + 2].gx = (w[i].b - max(w[i].a, w[i].c));
			jisuan[(i - 1) * 3 + 2].ren = i;
			jisuan[(i - 1) * 3 + 3].fang = 3;
			jisuan[(i - 1) * 3 + 3].gx = (w[i].c - max(w[i].a, w[i].b));
			jisuan[(i - 1) * 3 + 3].ren = i;
		}
		sort(jisuan + 1, jisuan + 3 * n + 1, cmp);
		int cnta = 0, cntb = 0, cntc = 0;
		int ans = 0;
		for(int i = 1; i <= 3 * n; i++){
			if(jisuan[i].fang == 1 && vis[jisuan[i].ren] == 0 && cnta < n / 2){
				vis[jisuan[i].ren] = true;
				cnta++;
				ans += w[jisuan[i].ren].a;
//				cout << jisuan[i].ren << " " << 1 << endl;
			}
			if(jisuan[i].fang == 2 && vis[jisuan[i].ren] == 0 && cntb < n / 2){
				vis[jisuan[i].ren] = true;
				cntb++;
				ans += w[jisuan[i].ren].b;
//				cout << jisuan[i].ren << " " << 2 << endl;
			}
			if(jisuan[i].fang == 3 && vis[jisuan[i].ren] == 0 && cntc < n / 2){
				vis[jisuan[i].ren] = true;
				cntc++;
				ans += w[jisuan[i].ren].c;
//				cout << jisuan[i].ren << " " << 3 << endl;
			}
		}
		printf("%d\n", ans);
	}
}
