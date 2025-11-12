#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 5e3+5;

int n,a[MAXN];
int ans;
int num[MAXN],vis[MAXN];

void dfs(int k,int pos) {
	if (pos > k) {
		int sum=0,maxn=-1;
		for (int i=1;i<=k;i++) {
			maxn = max(num[i],maxn);
			sum += num[i];
		}
		if (sum > 2*maxn){
			ans++;
		}
		return ;
	}
	for (int i=pos;i<=n;i++) {
		if (!vis[i]) {
			num[pos]=a[i];
			vis[i] = 1;
			dfs(k,pos+1);
			vis[i] = 0;
		}
	}
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=3;i<=n;i++) {
		for (int j=1;j<=n;j++) vis[j]=0;
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}