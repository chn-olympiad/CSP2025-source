#include<iostream>
#define int long long
const int N = 500 + 5,P = 998244353;
int n,m,c[N],cnt_1,ans;
char s[N];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s%d",&n,&m,&s);
	for(int i = 1; i <= n; i ++) {
		scanf("%d",c + i);
		cnt_1 += s[i] - '0';
	}
	if(m == 1) {
		int ans = 1;
		for(int i = 1; i <= n - 1; i ++) {
			ans *= i;
			ans %= P;
		}
		printf("%d\n",(ans * cnt_1) % P);
	} else if(m == n || cnt_1 == n) {
		if(cnt_1 == n) {
			for(int i = 1; i <= n; i ++) {
				ans *= i;
				ans %= P;
			}
			printf("%d\n",ans);
		}
		else{
			puts("0");
		}
	}
}
