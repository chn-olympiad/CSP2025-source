#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int mod=998244353;

int n,a[5005],ans,cnt[5005],flag=1;

void dfs(int x,int sum,int mx) {
	if(x>n) {
		if(sum>mx*2) ans++;
		return;
	}
	dfs(x+1,sum+a[x],max(mx,a[x]));
	dfs(x+1,sum,mx);
}
ll qpw(int x,int y) {
	ll res=1;
	while(y) {
		if(y&1) res=(res*x*1ll)%mod;
		x=(x*x*1ll)%mod;
		y>>=1;
	}
	return res;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(!(a[i]==1&&flag==1)) flag=0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
