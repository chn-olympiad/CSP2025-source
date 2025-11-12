#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010,M=100010;
const ll p=998244353ll;
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
ll fac[M],inv[M];

ll power(ll x,ll y){
	ll res=1;
	for(;y;y>>=1){
		if(y&1) res=res*x%p;
		x=x*x%p;
	}
	return res;
}

ll C(ll x,ll y){
	if(x<y||x<0||y<0) return 0;
	return fac[x]*inv[y]%p*inv[x-y]%p;
}

void init(ll n){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	inv[n]=power(fac[n],p-2);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
}

ll n,m;
ll s[N],cnt[N];
ll a[N],sum[N];
ll f[2][N][N],g[2][N][N];
ll ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init(10000);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char c=getchar();
		while(c!='0'&&c!='1') c=getchar();
		s[i]=c-'0';
		cnt[i]=cnt[i-1]+(!s[i]);
	}
	for(int i=1;i<=n;i++) a[read()]++;sum[0]=a[0];
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	f[1][0][0]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(!g[i&1][j][k]) continue;
				for(int l=0;l<=a[j];l++){
					f[i&1][j][k+l]=(f[i&1][j][k+l]+g[i&1][j][k]*C(a[j],l)%p*C(i-cnt[i-1]-k-1,l)%p*fac[l]%p)%p;
				}
				g[i&1][j][k]=0;
			}
		}
		if(i==n+1) break;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(!f[i&1][j][k]) continue;
				if(!s[i]){
					g[~i&1][j+1][k]=(g[~i&1][j+1][k]+f[i&1][j][k])%p;
				}
				else{
					g[~i&1][j+1][k+1]=(g[~i&1][j+1][k+1]+f[i&1][j][k]*(sum[j]-k)%p)%p;
					f[~i&1][j][k]=(f[~i&1][j][k]+f[i&1][j][k])%p;
				}
				f[i&1][j][k]=0;
			}
		}
	}
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n;j++){
			ans=(ans+f[(n+1)&1][i][j]*C(sum[n]-sum[i],n-j-cnt[n])%p*fac[n-j-cnt[n]]%p)%p;
		}
	}
	write(ans*fac[cnt[n]]%p),putchar('\n');
	return 0;
}
