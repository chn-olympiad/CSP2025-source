#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans1 = 0, ans2 = 0, ans3 = 0, ans = 0, tot1 = 0, tot2 = 0, tot3 = 0;
struct node{
	int a, b, c;
}ma[100007];
int vis[100007];
int n;
void dfs(int now){
	if(now == n + 1){
		ans = max(ans, ans1 + ans2 + ans3);
		return;
	}
	if(tot1 < n / 2){
		tot1++;
		ans1 += ma[now].a;
		dfs(now + 1);
		tot1--;
		ans1 -= ma[now].a;
	}
	if(tot2 < n / 2){
		tot2++;
		ans2 += ma[now].b;
		dfs(now + 1);
		tot2--;
		ans2 -= ma[now].b;
	}
	if(tot3 < n / 2){
		tot3++;
		ans3 += ma[now].c;
		dfs(now + 1);
		tot3--;
		ans3 -= ma[now].c;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;++i){
			cin >> ma[i].a >> ma[i].b >> ma[i].c;
		}
		ans = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
