#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, v[10];
struct node{
	int a, b, c, w, k, u;
}s[N];
struct note{
	int e, g;
}d[N];
bool cmp(node x, node y){return x.k > y.k;}
bool cmq(note x, note y){return x.e > y.e;}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		long long ans = 0, f = 0, t = 0;
		for(int i = 1; i <= 10; i++) v[i] = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
			if(s[i].a >= s[i].b && s[i].a >= s[i].c) s[i].w = 1, s[i].k = s[i].a;
			else if(s[i].b >= s[i].a && s[i].b >= s[i].c) s[i].w = 2, s[i].k = s[i].b;
			else s[i].w = 3, s[i].k = s[i].c;
			if(s[i].w == 1) s[i].u = max(s[i].b, s[i].c);
			else if(s[i].w == 2) s[i].u = max(s[i].a, s[i].c);
			else s[i].u = max(s[i].b, s[i].a);
			v[s[i].w]++;
			if(v[s[i].w] > n / 2) f = s[i].w;
		}
		sort(s + 1, s + n + 1, cmp);
		if(!f){
			for(int i = 1; i <= n; i++) ans += s[i].k;
		}else{
			for(int i = 1; i <= n; i++){
				if(s[i].w != f) ans += s[i].k;
				else{
					d[++t].e = s[i].k - s[i].u;
					d[t].g = s[i].k;
				}
			}
			sort(d + 1, d + t + 1, cmq);
			for(int i = 1; i <= n / 2; i++) ans += d[i].g;
			for(int i = n / 2 + 1; i <= t; i++) ans = ans + d[i].g - d[i].e;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
