#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t, n;
long long ans;
struct node{
	int d1, d2, d3;
}a[N];
priority_queue<int, vector<int>, greater<int> > q[4];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i].d1, &a[i].d2, &a[i].d3);
			int x = max(a[i].d1, max(a[i].d2, a[i].d3));
			if(a[i].d1 == x){
				q[1].push(x - max(a[i].d2, a[i].d3));
				ans += x;
			}
			else if(a[i].d2 == x){
				q[2].push(x - max(a[i].d1, a[i].d3));
				ans += x;
			}
			else if(a[i].d3 == x){
				q[3].push(x - max(a[i].d1, a[i].d2));
				ans += x;
			}
		}
		while(q[1].size() > n / 2){
			int u = q[1].top();
			q[1].pop();
			ans = ans - u;
		}
		while(q[2].size() > n / 2){
			int u = q[2].top();
			q[2].pop();
			ans = ans - u;
		}
		while(q[3].size() > n / 2){
			int u = q[3].top();
			q[3].pop();
			ans = ans - u;
		}
		printf("%lld\n", ans);
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
	}
	return 0;
}
