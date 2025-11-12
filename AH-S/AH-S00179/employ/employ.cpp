#include <iostream>
using namespace std;
const int N = 5e2 + 5;
const int MOD = 998244353;
char op;
int n,m,ans,s[N],c[N],a[N];
bool v[N];
void dfs(int step) {
	if (step>n) {
		int fail=0,success=0;
		for (int i=1; i<=n; i++) {
			if (!s[i] || fail>=a[i]) fail++;
			else success++;
		}
		if (success>=m) ans++;
		return;
	}
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			a[step]=c[i];
			v[i]=true;
			dfs(step+1);
			a[step]=0;
			v[i]=false;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for (int i=1; i<=n; i++) {
		cin>>op;
		if (op=='0') flag=false;
		s[i]=op-'0';
	}
	if (flag) {
		ans=1;
		for (int i=1; i<=n; i++) ans=ans*1ll*i%MOD;
		cout<<ans;
		return 0;
	}
	for (int i=1; i<=n; i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
