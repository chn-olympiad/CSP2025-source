#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define PII pair<int,int> 
using namespace std;
const int MAXN = 5e2 + 10;
const int MR = (1<<18) + 10;
const int mod = 998244353;

int n,m;
int fac[MAXN],id[MAXN];
int s[MAXN],c[MAXN];
bool A=1;

void solve10(){
	int ans=0;
	FL(i,1,n) id[i]=i;
	do{
		int now=0;
		FL(i,1,n){
			if(now>=c[id[i]]){
				now++;
				continue;
			}
			now+=(s[i]==0);
		}
		if(n-now>=m) ans=(ans+1)%mod;
	}while(next_permutation(id+1,id+n+1));
	printf("%d\n",ans);
} 

int f[MR][20];

void solve18(){
	int U=(1<<n)-1;
	f[0][0]=1;
	FL(S,0,U-1){
		int t=__builtin_popcount(S)+1; 
		FL(j,0,n){
			if(!f[S][j]) continue;
			FL(i,1,n){
				if(S&(1<<i-1)) continue;
				int op=(j>=c[i]||s[t]==0);
				f[S|(1<<i-1)][j+op]=(f[S|(1<<i-1)][j+op]+f[S][j])%mod;
			}
		}
	}
	int ans=0;
	FL(i,0,n-m) ans=(ans+f[U][i])%mod;
	printf("%d\n",ans);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ2.in","r",stdin); 
	scanf("%d%d",&n,&m);
	fac[0]=1;
	FL(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	FL(i,1,n) scanf("%1d",&s[i]),A&=(s[i]==1);
	FL(i,1,n) scanf("%d",&c[i]);
	if(n<=10) solve10(),exit(0);
	if(n<=18) solve18(),exit(0);
	return 0; 
} 
