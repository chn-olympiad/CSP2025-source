#include <bits/stdc++.h>
using namespace std;
int ans=0;
int n,a[5005];
bool cmp(int x,int y) {
	return x>y;
}
void dfs(int x,int sum,int maxn) {
	if(x>n) {
		return ;
	}
	if(sum>2*maxn) {
		ans++;
	}
	dfs(x+1,sum+a[x],maxn);
	dfs(x+1,sum,maxn);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i) {
		dfs(i,0,a[i]);
	}
	cout<<ans;
}
