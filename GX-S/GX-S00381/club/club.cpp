#include <bits/stdc++.h>
using namespace std;
struct node{
	int l, id;
};
bool cmp(node x,node y){
	return x.l > y.l;
}
int t, n, hf;
node a1[200020],a2[200020],a3[200020];
long long dp[200020];
bool per[200020];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		hf = n >> 1;
		for(int i = 1; i <= n; i++){
			cin >> a1[i].l >> a2[i].l >> a3[i].l;
			a1[i].id = i;
			a2[i].id = i;
			a3[i].id = i;
			per[i] = 1;
		}
		sort(a1 + 1,a1 + n + 1,cmp);
		sort(a2 + 1,a2 + n + 1,cmp);
		sort(a3 + 1,a3 + n + 1,cmp);
		int i = 1, j = 1, k = 1;
		for(int s = 1; s <= n; s++){
			dp[s] = dp[s - 1];
			int p = 1;
			if(per[a1[i].id] && i <= hf)dp[s] = dp[s - 1] + a1[i].l;
			if(a2[j].l + dp[s - 1] > dp[s] && per[a2[j].id] && j <= hf){
				dp[s] = dp[s - 1] + a2[j].l;
				p = 2;
			}
			if(a3[k].l + dp[s - 1] > dp[s] && per[a3[k].id] && k <= hf){
				dp[s] = dp[s - 1] + a3[k].l;
				p = 3;
			}
			if(p == 1) per[a1[i++].id] = 0;
			else if(p == 2) per[a2[j++].id] = 0;
			else per[a3[k++].id] = 0;
		}
		cout << dp[n] << '\n';
		memset(per, 0, sizeof(per));
	}
	return 0;
}
