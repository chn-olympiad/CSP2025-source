#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10020];
int b[10020];
int c[10020];
int vis[10020];
int club[10];
int ans = -100000000;
bool cmp(int a,int b){
	return a > b;
}
void dfs(int x, int sum){
	if(x == n+1){
		ans = max(ans,sum);
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(club[i] >= (n/2)) continue;
		vis[x] = i;
		club[i]++;
		if(i == 1){
			dfs(x+1,sum+a[x]);
		}else if(i == 2){
			dfs(x+1,sum+b[x]);
		}else{
			dfs(x+1,sum+c[x]);
		}
		vis[x] == 0;
		club[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		for(int i = 1; i <= 10; i++){
			club[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			vis[i] = 0;
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cin >> n;
		int cnt2 = 0;
		int cnt3 = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] == 0) cnt2++;
			if(c[i] == 0) cnt3++;
		}
		if(cnt2 == n && cnt3 == n){
			sort(a+1,a+n+1,cmp);
			for(int i = 1; i <= (n/2); i++){
				ans += a[i];
			}
			cout << ans << endl;
			continue;
		}
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}
