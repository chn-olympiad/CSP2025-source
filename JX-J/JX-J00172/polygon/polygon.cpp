#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int n,ans,a[N];
bool o[N];
void dfs(int step){
	if(step == n + 1){
		int sum = 0,mx = -1,cnt = 0;
		for(int i = 1 ; i <= n ; i ++)
			if(o[i]) sum += a[i],mx = max(mx,a[i]),cnt ++;
		//for(int i = 1 ; i <= n ; i ++)
		//	cout << o[i] << ' ';
		//cout << '\n';
		if(cnt >= 3 && sum > 2 * mx) ans ++;
		return;
	}
	o[step] = 0;
	dfs(step + 1);
	o[step] = 1;
	dfs(step + 1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
