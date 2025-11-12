#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
	char c;x=0;bool f=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=505;
const int mod=998244353;
char a[N];
int n,m,c[N],dp[N][N],f[N][N],p[N],fac[N];
inline void Add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	in(n),in(m),scanf("%s",a+1);
	for(int i=fac[0]=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		in(c[i]);
		for(int j=c[i];j<=n;j++)p[j]++;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]=='0')continue;
		for(int j=0;j<=i;j++)for(int k=0;k<=i;k++)f[j][k]=dp[j][k],dp[j][k]=0;
		for(int j=0;j<=i;j++)for(int k=0;k<i;k++){
			if(f[j][k]&&p[j]>k)Add(dp[j][k+1],1ll*(p[j]-k)*f[j][k]%mod);
			if(!j)continue;
			if(f[j-1][k]&&p[j-1]>k)Add(dp[j][k+1],mod-1ll*(p[j-1]-k)*f[j-1][k]%mod);
			if(f[j-1][k])Add(dp[j][k],f[j-1][k]);
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)for(int j=0;j<=n;j++)if(dp[i][j])Add(ans,1ll*fac[n-j]*dp[i][j]%mod);
	cout<<ans<<endl;
	return 0;
}