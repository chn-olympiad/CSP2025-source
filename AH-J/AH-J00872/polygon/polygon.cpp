#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
typedef unsigned long long ull;
int a[5005],ans[5005],n,kkk = 0,yx[5005][5005],vvv = 1;
bool check(int n) {
	for (int i = 1;i<=vvv;i++)
		for (int j = 1;j<=n;j++)
		   if (ans[j]!=yx[i][j]) return 1;
	return 0;
}
void dfs(int top,int now) {
	if (now==n+1) {
		int sum = 0;
		for (int i = 1;i<top;i++) sum+=ans[i];
		if (sum>ans[top-1]&&top>=4&&check(top-1)) {
			for (int i = 1;i<top;i++)
				yx[vvv][i] = ans[i];
			vvv++,kkk++;
		}
		return;
	}
	for (int i = now;i<=n;i++) {
		ans[top] = a[i];
		dfs(top+1,i+1);
		ans[top] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<kkk;
}
