#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
long long ans;
void dfs(long long x,int num,int s) {
	if (s==num-1) {
		if (x>a[num]) ans++;
		ans%=mod;
		return ;
	}
	dfs(x+a[s+1],num,s+1);
	dfs(x,num,s+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++) dfs(0,i,0);
	cout<<ans<<endl;
	return 0;
}
