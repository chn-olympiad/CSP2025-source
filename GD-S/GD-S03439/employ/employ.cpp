#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
char ch[505];
int c[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ans = 1;
	for(int i = 1;i <= n;i++) {
		ans *= i;
		ans %= mod;
	}
	printf("%d",ans);
	return 0;
}
