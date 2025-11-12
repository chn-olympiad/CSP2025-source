#include <iostream>
#include <cstdio>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std;
const int N=1e5+5;
int T, n, a[N][3], cnt[3], ans, k;
priority_queue<int, vector<int>, greater<int> > h[3];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
			if(a[i][0] > a[i][1]) a[i][0] > a[i][2] ? k=0 : k=2;
			else a[i][1] > a[i][2] ? k=1 : k=2;
			int p = max(a[i][0], max(a[i][1], a[i][2])), q = min(a[i][0], min(a[i][1], a[i][2]));
			h[k].push(p - (a[i][0]+a[i][1]+a[i][2]-p-q));
			ans += p;
		}
		for(int k=0; k<=2; k++){
			while(h[k].size() > n/2){
				ans -= h[k].top();
				h[k].pop();
			}
			while(!h[k].empty()) h[k].pop();
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
