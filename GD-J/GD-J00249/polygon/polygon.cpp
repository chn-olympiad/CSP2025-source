#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt=0,b[5005],ans=0;
void dfs(int t) {
	if(t>n) {
		int maxn=-1,sum=0;
		for(int i=1;i<=cnt;i++) {
			maxn=max(maxn,b[i]);
			sum+=b[i];
		}
		if(maxn*2<sum) ans=(ans+1)%998244353;
		return ;
	}
	b[++cnt]=a[t];
	dfs(t+1);
	cnt--;
	dfs(t+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
