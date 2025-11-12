#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
struct node{
	int a = 0, b = 0, c = 0;
}g[N];
int p1[N], p2[N], p3[N], c[4], f[4];
bool cmp1(int A, int B){
	return min(g[A].a - g[A].b, g[A].a - g[A].c) < 
			min(g[B].a - g[B].b, g[B].a - g[B].c);
}
bool cmp2(int A, int B){
	return min(g[A].b - g[A].a, g[A].b - g[A].c) < 
			min(g[B].b - g[B].a, g[B].b - g[B].c);
}
bool cmp3(int A, int B){
	return min(g[A].c - g[A].a, g[A].c - g[A].b) < 
			min(g[B].c - g[B].a, g[B].c - g[B].b);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t --){
		memset(p1, 0, sizeof p1);
		memset(p2, 0, sizeof p2);
		memset(p3, 0, sizeof p3);
		memset(c, 0, sizeof c);
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= 2*n; i ++) g[i].a = g[i].b = g[i].c = 0;
		for(int i = 1; i <= n; i ++){
			scanf("%d %d %d", &g[i].a, &g[i].b, &g[i].c);
			int maxn = max(g[i].a, max(g[i].b, g[i].c));
			if(maxn == g[i].a) p1[++c[1]] = i;
			else if(maxn == g[i].b) p2[++c[2]] = i;
			else if(maxn == g[i].c) p3[++c[3]] = i;
		}
		f[1] = f[2] = f[3] = 1;
		if(c[1] > n / 2){
			sort(p1 + 1, p1 + 1 + c[1], cmp1);
			for(int i = 1; i <= c[1] - n/2; i ++){
				f[1] ++;
				int x = g[p1[i]].a - g[p1[i]].b;
				int y = g[p1[i]].a - g[p1[i]].c;
				if(x < y) p2[++ c[2]] = p1[i];
				else p3[++ c[3]] = p1[i];
			}
		}
		else if(c[2] > n / 2){
			sort(p2 + 1, p2 + 1 + c[2], cmp2);
			for(int i = 1; i <= c[2] - n/2; i ++){
				f[2] ++;
				int x = g[p2[i]].b - g[p2[i]].a;
				int y = g[p2[i]].b - g[p2[i]].c;
				if(x < y) p1[++ c[1]] = p2[i];
				else p3[++ c[3]] = p2[i];
			}
		}
		else if(c[3] > n / 2){
			sort(p3 + 1, p3 + 1 + c[3], cmp3);
			for(int i = 1; i <= c[3] - n/2; i ++){
				f[3] ++;
				int x = g[p3[i]].c - g[p3[i]].a;
				int y = g[p3[i]].c - g[p3[i]].b;
				if(x < y) p1[++ c[1]] = p3[i];
				else p2[++ c[2]] = p3[i];
			}
		}
		long long ans = 0ll;
		for(int i = f[1]; i <= c[1]; i ++) ans += 1ll * g[p1[i]].a;
		for(int i = f[2]; i <= c[2]; i ++) ans += 1ll * g[p2[i]].b;
		for(int i = f[3]; i <= c[3]; i ++) ans += 1ll * g[p3[i]].c;
		printf("%lld\n", ans);
	}
	return 0;
}
