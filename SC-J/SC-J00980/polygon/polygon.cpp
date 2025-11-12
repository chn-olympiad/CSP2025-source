#include<bits/stdc++.h>
using namespace std;
int n,a[5100],ans,b[5100],w,sx;
void dfs(int x,int m) {
	if(x>w) {
		int sum=0;
		for(int i=1; i<=m; i++)sum+=b[i];
		if(sum>sx)ans++;
		return;
	}
	b[m]=a[x];
	dfs(x+1,m+1);
	b[m]=0;
	dfs(x+1,m);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n-2; i++) {
		for(int j=i+2; j<=n; j++) {
			w=j-1;
			sx=a[j]-a[i];
			dfs(i+1,1);
		}
	}
	cout<<ans;
	return 0;
}