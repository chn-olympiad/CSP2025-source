#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5;
int T,n;
struct Member {
	int a,b,c;
} d[MAXN+10];
long long mymax(long long x,long long y) {
	return x>y?x:y;
}
long long f[210][210][210];
bool mycmpA(Member x,Member y) {
	return x.a>y.a;
}
bool mycmpB(Member x,Member y) {
	return x.a-x.b>y.a-y.b;
}
void solve(void) {
	if(n<=200) {
		long long ans=0;
		int mid=n>>1;
		for(int i=0; i<=n+1; i++) {
			for(int j=0; j<=n+1; j++) {
				for(int k=0; k<=n+1; k++) {
					f[i][j][k]=0;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=i&&j<=mid; j++) {
				for(int k=0; k<=i&&k<=mid; k++) {
					if(j-1>=0) {
						f[i][j][k]=mymax(f[i-1][j-1][k]+d[i].a,f[i][j][k]);
					}
					if(k-1>=0) {
						f[i][j][k]=mymax(f[i-1][j][k-1]+d[i].b,f[i][j][k]);
					}
					if(i-1-j-k>=0) {
						f[i][j][k]=mymax(f[i-1][j][k]+d[i].c,f[i][j][k]);
					}
				}
			}
		}
		for(int i=0; i<=mid; i++) {
			for(int j=0; j<=mid; j++) {
				if(n-i-j<=mid) {
					ans=mymax(ans,f[n][i][j]);
				}
			}
		}
		printf("%lld\n",ans);
	} else {
		bool f2=true,f3=true;
		for(int i=1; i<=n; i++) {
			if(d[i].b!=0) {
				f2=false;
			}
			if(d[i].c!=0) {
				f3=false;
			}
		}
		if(f2&&f3) {
			sort(d+1,d+1+n,mycmpA);
			long long ans=0;
			for(int i=1; i<=(n>>1); i++) {
				ans+=d[i].a;
			}
			printf("%lld\n",ans);
		} else if(f3) {
			sort(d+1,d+1+n,mycmpB);
			long long ans=0;
			for(int i=1; i<=(n>>1); i++) {
				ans+=d[i].a;
			}
			for(int i=(n>>1)+1; i<=n; i++) {
				ans+=d[i].b;
			}
			printf("%lld\n",ans);
		}
	}
	return;
}
int main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		for(int i=0; i<=n+1; i++) {
			d[i].a=d[i].b=d[i].c=0;
		}
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
		}
		solve();
	}
	return 0;
}
