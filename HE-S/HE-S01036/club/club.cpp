#include <bits/stdc++.h>
using namespace std;
int n,t,a[114514][5],ans,res = 0,cnt[141514];
void dfs(int x,int sum) {
	if(x == n+1) {
		ans = max(ans,sum);
		return;
	}
	if(cnt[1] < n/2)  {
		cnt[1]++;
		dfs(x+1,sum+a[x][1]);
		cnt[1]--;
	}
	if(cnt[2] < n/2)  {
		cnt[2]++;
		dfs(x+1,sum+a[x][2]);
		cnt[2]--;
	}
	if(cnt[3] < n/2)  {
		cnt[3]++;
		dfs(x+1,sum+a[x][3]);
		cnt[3]--;
	}
}
int main() {
	//tle20
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) cin >> a[i][j];
		}
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}
