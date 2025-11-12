#include<bits/stdc++.h>
const int N = 1e5 + 5;
int n,ans,T;
int f[205][105][105];//选前i个，a用了j个，b用了k个，c用了i - j - k个
struct node {
	int a,b,c;
	bool operator < (node o) const {
		return std::max(a,std::max(b,c)) > std::max(o.a,std::max(o.b,o.c));
	}
} a[N];
bool flag1 = 1,flag2 = 1;
void solve() {
	memset(f,0,sizeof f);
	memset(a,0,sizeof a);
	flag1 = 1,flag2 = 1,ans = 0,n = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
		flag1 &= (a[i].b == 0) && (a[i].c == 0);
	}
	if(flag1) {
		std::sort(a + 1,a + n + 1);
		for(int i = 1; i <= n / 2; i ++) {
			ans += a[i].a;
		}
		printf("%d\n",ans);
	} else if(n <= 200) {
		for(int i = 1; i <= n; i ++) {
			f[i][0][0] = f[i - 1][0][0] + a[i].c;//a,b = 0
			f[i][i][0] = f[i - 1][i - 1][0] + a[i].a;//b,c = 0
			f[i][0][i] = f[i - 1][0][i - 1] + a[i].b;//a,c = 0
			for(int a_n = 1; a_n <= std::min(n / 2,i - 1); a_n ++) {
				f[i][a_n][0] = std::max(f[i - 1][a_n - 1][0] + a[i].a,f[i - 1][a_n][0] + a[i].c); // b = 0
				f[i][0][a_n] = std::max(f[i - 1][0][a_n - 1] + a[i].b,f[i - 1][0][a_n] + a[i].c); // a = 0
				f[i][a_n][i - a_n] = std::max(f[i - 1][a_n - 1][i - a_n] + a[i].a,f[i - 1][a_n][i - a_n - 1] + a[i].b);//c = 0
				for(int b = 1; b <= std::min(n / 2,i - a_n - 1); b ++) {
					int c = i - a_n - b;
					if(c > n / 2) continue;
					f[i][a_n][b] = std::max(f[i - 1][a_n - 1][b] + a[i].a,std::max(f[i - 1][a_n][b - 1] + a[i].b,f[i - 1][a_n][b] + a[i].c));
				}
			}
		}
		for(int a_n = 0; a_n <= n / 2; a_n ++) {
			for(int b = 0; b <= std::min(n / 2,n - a_n); b ++) {
				int c = n - a_n - b;
				if(c > n / 2) continue;
				ans = std::max(ans,f[n][a_n][b]);
			}
		}
		printf("%d\n",ans);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T --) {
		solve();
	}
}
