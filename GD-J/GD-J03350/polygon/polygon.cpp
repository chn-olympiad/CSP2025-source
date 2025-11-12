#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5001];
long long l;
long long ans;
void dfs(long long x,long long y,long long ma) {
	if(x==n) {
		if(y>2*ma) {
			ans++;
		}
		if(y+a[x]>2*max(ma,a[x])) {
			ans++;
		}
		return;
	}
	dfs(x+1,y+a[x],max(ma,a[x]));
	dfs(x+1,y,ma);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=20) {
		dfs(2,0,0);
		dfs(2,a[1],a[1]);
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
