#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n,cnt;
int a[N];

void dfs(int now,int sum,int maxn,int choose){
	if(now == n + 1){
		if(choose >= 3 && sum > 2 * maxn && sum > 0) cnt++;
		return;
	}
	dfs(now + 1,sum + a[now],max(maxn,a[now]),choose + 1);
	dfs(now + 1,sum,maxn,choose);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(1,0,0,0);
	cout << cnt;
	return 0;
}