#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=505,mod=998244353;
int f[N],n,ans,a[N];
bool flag;
void dfs(int x,int mx,int sum) {
	if(x>n) {
		if(mx*2<sum) ans++;
	} else {
		dfs(x+1,a[x],sum+a[x]);
		dfs(x+1,mx,sum);
	}
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	sort(a+1,a+1+n);
	if(flag) {
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}else{
		int k=n-2;
		ans=(1+k)*k/2;
		cout<<ans;
		return 0;
	}
}
