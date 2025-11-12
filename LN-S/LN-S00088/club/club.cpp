#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N][4], vis[N], q[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
        memset(vis, 0, sizeof(vis));
		int cnt[4] = {0}, p = 0, tot = 0;
		long long ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if(a[i][1] == max(a[i][2], a[i][3]) || a[i][2] == max(a[i][1], a[i][3]) || a[i][3] == max(a[i][1], a[i][2])) ++cnt[0], vis[i] = 0;
            else if(a[i][1] > max(a[i][2], a[i][3])) ++cnt[1], vis[i] = 1;
            else if(a[i][2] > max(a[i][1], a[i][3])) ++cnt[2], vis[i] = 2;
            else ++cnt[3], vis[i] = 3;
            ans += max(a[i][1], max(a[i][2], a[i][3]));
		}
		for(int i = 1; i <= 3; i++) if(cnt[i] > n/2) p = i;
        for(int i = 1; i <= n; i++){
            if(vis[i] == p){
                int c = 0;
                if(p == 1) c = a[i][1] - max(a[i][2], a[i][3]);
                else if(p == 2) c = a[i][2] - max(a[i][1], a[i][3]);
                else c = a[i][3] - max(a[i][1], a[i][2]);
                q[++tot] = c;
            }
        }
        sort(q+1, q+tot+1);
        for(int i = 1; i <= tot-n/2; i++){
            ans -= q[i];
        }
		printf("%lld\n", ans);
	}
	return 0;
}
