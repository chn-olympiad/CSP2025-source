#include<bits/stdc++.h>
#define Mp make_pair
#define eb emplace_back
#define il inline
#define pc putchar
#define gc getchar
#define mems(x,y) memset(x,y,sizeof x)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define drep(i,x,y) for(int i=(x);i>=(y);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=507,M=-1,inf=0x3f3f3f3f,mod=998244353;
const ll INF=1ll*inf*inf;
int n,m,a[N],c[N],dp[1<<19][21];
char s[N];
il int Mod(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
void Sana(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	rep(i,1,n){
		a[i]=s[i]-'0';
	}
	rep(i,1,n){
		scanf("%d",&c[i]);
	}
	if(n<=18){
		const int all=1<<n;
		dp[0][0]=1;
		rep(S,0,all-1){
			int p=__builtin_popcount(S)+1;
			rep(j,0,n){
				rep(i,1,n){
					if(S>>(i-1)&1){
						continue;
					}
					int T=S|1<<(i-1),w=j+((!a[p])|(j>=c[i]));
					dp[T][w]=Mod(dp[T][w],dp[S][j]);
				}
			}
		}
		int ans=0;
		rep(i,0,n-m){
			ans=Mod(ans,dp[all-1][i]);
		}
		printf("%d\n",ans);
	}else if(m==n){
		bool fl=1;
		int ans=1;
		rep(i,1,n){
			ans=1ll*ans*i%mod;
			fl&=a[i]&&c[i];
		}
		printf("%d\n",fl*ans);
		
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
	// scanf("%d",&t);
	while(t--){	
		Sana();
	}
}
