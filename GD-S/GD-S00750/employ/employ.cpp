#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define Rep(i,a,b) for(int i = (a);i >= (b);--i)

using ll = long long;

const int N = 505;
const ll mod = 998244353;

int n,m0,p[N],c[N],b[N],bs[N];
ll f[N][N][N],F[N],G[N],I[N],ans;
char a[N];

ll C(int n,int m){ return F[n] * G[m] % mod * G[n - m] % mod; }

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m0,a + 1);
	rep(i,1,n) a[i] -= '0';
	rep(i,1,n) scanf("%d",c + i),++b[c[i]];
	Rep(i,n,0) bs[i] = bs[i - 1] + b[i];
	if(m0 == n){
		bool flg = 1;
		rep(i,1,n) flg &= a[i] == 1,flg &= c[i] > 0;
		return printf("%d\n",flg),0;
	}
	if(n <= 10){
		rep(i,1,n) p[i] = i;
		do {
			int d = 0;
			rep(j,1,n) d += c[p[j]] <= d || !a[j];
			if(n - d >= m0) ++ans;
		} while(next_permutation(p + 1,p + n + 1));
		printf("%lld\n",ans);
		return 0;
	}
	F[0] = G[0] = I[1] = 1;
	rep(i,1,N - 1){
		if(i > 1) I[i] = (mod - mod / i) * I[mod % i] % mod;
		F[i] = F[i - 1] * i % mod,G[i] = G[i - 1] * I[i] % mod;
	}
	rep(m,0,n - m0){
		memset(f,0,sizeof f);
		f[n + 1][0][m + 1] = 1;
		// i~n, k failers, failer cnt k~n=j
		Rep(i,n,1){
			rep(i1,i + 1,n + 1){
				rep(j,0,n) rep(k,0,m) if(f[i1][j][k+1]){
					int c = m - k + 1;
					rep(j1,0,min(c - j,b[k])){
//						printf("# %d %d %d:%d %d %d:| %d %d %lld %lld\n",i1,j,k+1,i,j+j1,k,c,j1,C(c-j,j1),C(i1-i-1,bs[k+1]-j));
						(f[i][j + j1][k] += f[i1][j][k + 1] * C(c - j,j1) % mod * C(b[k],j1) % mod * F[j1] % mod * F[j1] % mod * C(i1 - i - 1,bs[k + 1] - j) % mod) %= mod;
					}
				}
				if(a[i1] == 0) break;
			}
		}
//		Rep(i,n,1) rep(j,0,n) rep(k,0,m) if(f[i][j][k]) printf("%d %d %d:%lld\n",i,j,k,f[i][j][k]);
		rep(i,1,n){
			rep(j,0,n) (ans += f[i][j][1]) %= mod;
			if(a[i] == 0) break;
		}
//		printf("# %d:%lld\n",m,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
