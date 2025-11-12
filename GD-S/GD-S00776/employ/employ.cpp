#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,m,a[100005],ans,y[100005];
void dfs(int i,int q) {
	if(q>m) return;
	if(i==n+1) return void(ans++);
	for(int j = 1;j <= n;j ++) if(y[j]==0) {
		if(s[i]=='1'&&q<a[j]) y[j]=1,dfs(i+1,q),y[j]=0;
		else y[j]=1,dfs(i+1,q+1),y[j]=0;
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s,s=" "+s;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	dfs(1,0);
	cout << ans;
	return 0;
}
