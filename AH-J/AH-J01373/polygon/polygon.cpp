#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;
void dfs(int m,int x,int s) {
	if(m == n+1) {
		if(x > s*2) {
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	dfs(m+1,x+a[m],max(s,a[m]));
	dfs(m+1,x,s);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	dfs(1,0,0);
	cout<<ans<<endl;
}
