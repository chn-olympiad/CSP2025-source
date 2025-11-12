#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 998244353;
int n,ans,a[N];
bool v[N];
void dfs(int p, int step, int sum, int Max) {
	if (step>=3 && sum>2*Max) ans++;
	for (int i=p+1; i<=n; i++) {
		if (!v[i]) {
			v[i]=true;
			dfs(i,step+1,sum+a[i],max(Max,a[i]));
			v[i]=false;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (n==3) {
		if (a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if (a[1]==1 && a[n]==1) {
		long long ans=0;
		for (int i=3; i<=n; i++) {
			long long a=1,b=1,c=1;
			for (int j=1; j<=n; j++) {
				if (j<=i) a=a*1ll*j%MOD;
				if (j<=n-i) b=b*1ll*j%MOD;
				c=c*1ll*j%MOD;
			}
			ans=ans+c/a/b;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%MOD;
	return 0;
}
