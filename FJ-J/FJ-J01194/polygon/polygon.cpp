#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int P = 998244353;
void dfs(int k,int id,int sum,int maxn){
	if (k == 0){
		if (sum > maxn * 2) ans = (ans + 1) % P;
		return;
	}if (n - id + 1 < k) return;
	for (int i = id;i <= n;i++) dfs(k-1,i+1,sum+a[i],max(maxn,a[i]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 3;i <= n;i++) dfs(i,1,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
