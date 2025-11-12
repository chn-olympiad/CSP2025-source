#include <bits/stdc++.h>
using namespace std;
bool t[505];
int c[505],cnt,mod = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) cin >> t[i];
	for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
	long long ans = 1;
	for(int i = 2;i <= m;i++){
		ans *= m;
	}
	ans %= mod;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
