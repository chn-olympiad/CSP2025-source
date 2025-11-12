#include <bits/stdc++.h>
using namespace std;
struct node{
	int num, id, flag;
}d[100005], p[100005];
bool cmp(node px1, node px2){
	return px1.num < px2.num;
}
int js1[5], js2[100005], vis[100005];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int sum = 0;
		int y = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> d[y].num;
				d[y].id = i;
				d[y].flag = j;
				sum += d[y].num;
				y++;
			}
		}
		sort(d + 1, d + y, cmp);
		for(int i = 1; i <= 3; i++) js1[i] = n;
		for(int i = 1; i <= n; i++) js2[i] = 3;
		for(int i = 1; i < y; i++){
			if(js1[d[i].flag] > n/2 && js2[d[i].id] > 1){ 
			 d[i].num = -1;
			 js1[d[i].flag]--;
			 js2[d[i].id]--;
			}
		}
		int m = 1;
		for(int i = y - 1; i >= 1; i--){
			if(d[i].num != -1) p[m++] = d[i];
		}
		int ans = 0;
		memset(vis,0,sizeof(vis));
		for(int i = 1; i < m; i++){
			if(vis[p[i].id] == 0){
				ans += p[i].num;
				vis[p[i].id] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
