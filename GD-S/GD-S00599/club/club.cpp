//一定不会去到最不满意的社团 
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int INF=0x3f3f3f3f, M=1e5+5;
int n, ans, in1, in2, in3, tmp, mid, sum, idx;
priority_queue<int> g[5];
void init(){
	ans=0;
	for (int i=0; i<5; i++){
		while (!g[i].empty()){
			g[i].pop();
		}
	}
	return ;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%lld", &T);
	while (T--){
		init();
		scanf("%lld", &n);
		for (int i=1; i<=n; i++){
			scanf("%lld%lld%lld", &in1, &in2, &in3);
			sum = in1 + in2 + in3;
			mid = sum - max(in1, max(in2, in3)) - min(in1, min(in2, in3));
			in1-=mid, in2-=mid, in3-=mid, ans+=mid;
			if (in1 > 0) g[1].push(in1);
			if (in2 > 0) g[2].push(in2);
			if (in3 > 0) g[3].push(in3);
		} 
		for (int i=1; i<=3; i++){
			idx=1;
			while (!g[i].empty() && idx+idx <= n){
				idx++;
				ans+=g[i].top();
				g[i].pop();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
