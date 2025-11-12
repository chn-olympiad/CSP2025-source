#include<bits/stdc++.h>
using namespace std;
int n, cnt[3];
long long ans;
vector<int> v[3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _; scanf("%d", &_); while(_--){
		scanf("%d", &n);
		cnt[0] = cnt[1] = cnt[2] = ans = 0;
		v[0].clear(); v[1].clear(); v[2].clear();
		for(int i = 1; i <= n; i++){
			int a, b, c, id, e;
			scanf("%d%d%d", &a, &b, &c);
			if(a > b && a > c) id = 0, e = a - max(b, c);
			else if(b > c) id = 1, e = b - max(a, c);
			else id = 2, e = c - max(a, b);
			cnt[id]++, v[id].push_back(e), ans += max({a, b, c});
		}
		int md = -1;
		if(cnt[0] > n / 2) md = 0;
		if(cnt[1] > n / 2) md = 1;
		if(cnt[2] > n / 2) md = 2;
		if(md != -1){
			sort(v[md].begin(), v[md].end());
			for(int i = 0; cnt[md] > n / 2; cnt[md]--, i++) ans -= v[md][i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
