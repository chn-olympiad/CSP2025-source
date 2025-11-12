#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[50005], pre[50005], vis[50005];
int n, sum;
vector<int>v;
int cnt;
void dfs(int x, int maxi, int idx){
	if(x >= 3)
		if(maxi * 2 < sum){
			cnt++;
			cout << maxi << " " << sum << " " << idx <<  endl;
		}
	if(x == n + 1){
		return;
	}
	for(int i = idx; i <= n; i++){
		if(!vis[i]){
			sum += a[i];
			v.push_back(a[i]);
			dfs(x + 1, max(maxi, a[i]), i + 1);
			v.pop_back();
			sum -= a[i];
		}
	}
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int flag = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1)flag = 0;
	}
	if(flag){//È«ÊÇ1
		for(int i = 3; i <= n; i++){
			int p = 1, q = 1;
			for(int j = n; j >= n - i + 1; j--){
				p *= j;
			}
			for(int j = 1; j <= i; j++){
				q *= j;
			}
			cnt += p / q;
		}
		cout << cnt;
	}else{
		dfs(1, 0, 1);
		cout << cnt << endl;
	}
}
