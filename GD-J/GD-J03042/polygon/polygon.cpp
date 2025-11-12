#include<bits/stdc++.h>
using namespace std;
#define mod 998224353
int n;
int a[5005];
int ans;
void dfs(int cnt,int sum,int maxx,int pos) {
	if(cnt>=3 && sum>maxx*2) {
		ans++;
		ans%=mod;
	}
	if(cnt==n) {
		return ;
	}
	for(int i=pos+1;i<=n;i++) {
		dfs(cnt+1,sum+a[i],max(maxx,a[i]),i);
	}
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
