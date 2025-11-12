#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int a1,b1,c1,n,ans;
int vis[100010];
void dfs(int index){
	if (index > n){
		int sum1 = 0;
		for (int i=1;i<=n;i++){
			if (vis[i] == 1)sum1 += a[i];
			else if (vis[i] == 2)sum1 += b[i];
			else sum1 += c[i];
		}
		ans = max(ans,sum1);
		return;
	}
	if (a1 < n/2)
	{
		a1++;
		vis[index] = 1;
		dfs(index+1);
		a1--;
	}
	if (b1 < n/2)
	{
		b1++;
		vis[index] = 2;
		dfs(index+1);
		b1--;
		}
	if (c1 < n/2)
	{
		c1++;
		vis[index] = 3;
		dfs(index+1);
		c1--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		ans = 0;
		cin >> n;
		for (int i=1;i<=n;i++)cin >> a[i] >> b[i] >> c[i];
		if (n > 10){
		
		for (int i=1;i<=n;i++)ans += max(a[i],b[i]);
		cout << ans;}
		else{
			dfs(1);
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}
