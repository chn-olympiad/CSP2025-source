#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100086, inf = 0x3f3f3f3f, mod = 998244353;
struct node{
	int w, id;
	bool operator < (const node ttt) const{
		return w > ttt.w;
	}
}a[N][4];
priority_queue <node> q[4];
int T, n;
int s[4];
ll ans;
int main(){//100?
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		for(int i = 1; i <= 3; i++) while(q[i].size()) q[i].pop();
		ans = 0;
		s[1] = s[2] = s[3] = 0;
		
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++){
				scanf("%d", &a[i][j].w);
				a[i][j].id = j;
			}
			sort(a[i] + 1, a[i] + 4);
		}
		
		for(int i = 1; i <= n; i++){
			if(s[a[i][1].id] * 2 < n){
				q[a[i][1].id].push((node){a[i][1].w - a[i][2].w, a[i][1].id}); 
				ans += a[i][1].w, s[a[i][1].id]++;
			}
			else{
				node t = q[a[i][1].id].top();
				int dw = a[i][1].w - t.w;
				if(dw > 0){
					q[a[i][1].id].pop();
					q[a[i][1].id].push((node){a[i][1].w - a[i][2].w, a[i][1].id});
					q[a[t.id][2].id].push((node){a[t.id][2].w - a[t.id][3].w, a[t.id][2].id});
					s[a[t.id][2].id]++;
					ans += dw;
				}
				else{
					q[a[i][2].id].push((node){a[i][2].w - a[i][3].w, a[i][2].id});
					s[a[i][2].id]++;
					ans += a[i][2].w;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
