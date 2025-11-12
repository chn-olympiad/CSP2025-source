#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int n, a[5010], f[5010], als;
ll ans;

void dfs(int x, int sg){
	if (x>sg){
		int sum=0, maxx=-1;
		for (int i=1;i<=sg;++i){
			sum+=a[f[i]];
			maxx=max(maxx, a[f[i]]);
		}
		if (sum>2*maxx){
			ans++;
			if (ans>MOD) ans=1;
		}
	}
	for (int i=f[x-1]+1;i<=n;++i){
		f[x]=i;
		if (x>sg) break;
		dfs(x+1, sg);
		f[x]=0;
	}
}

void alss(){
	ll ans=1;
	for (int i=1; i<=n; ++i){
		ans = (ans * 2) % MOD;
	}
	cout << ans-1 << endl;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n<=3){
		int x, y, z;
		cin >> x >> y >> z;
		cout << ((x+y+z) > 2*max(max(x,y),z)) << endl;
		return 0;
	}
	for (int i=1;i<=n;++i){
		cin >> a[i];
		als+=(a[i]!=1);
	}
	if (!als){
		alss();
		return 0;
	}
	for (int i=3;i<=n;++i){
		dfs(1, i);
	}
	cout << ans << endl;
	return 0;
}
