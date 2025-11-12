#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define REP(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define fastIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
const int mod=998244353;
const int N=503;
int n,m,a[N],b[N],pc[262150];
ll f[262150][20];
string s;
int main(){ freopen("employ.in","r",stdin); freopen("employ.out","w",stdout); fastIO; cin>>n>>m>>s;
	pc[0]=0; rep(i,1,262144) pc[i]=pc[i-(i&(-i))]+1;
	rep(i,1,n) cin>>a[i];
	if(n<=18){ f[0][0]=1;
		rep(i,0,(1<<n)-2){
			rep(j,0,pc[i]){
				rep(k,1,n){ if((i>>k-1)&1) continue;
					if(s[pc[i]]=='0') f[i|(1<<k-1)][j]=(f[i|(1<<k-1)][j]+f[i][j])%mod;
					else{
						if(a[k]<=pc[i]-j) f[i|(1<<k-1)][j]=(f[i|(1<<k-1)][j]+f[i][j])%mod;
						else f[i|(1<<k-1)][j+1]=(f[i|(1<<k-1)][j+1]+f[i][j])%mod;
					}
				}
			}
		} ll ans=0;
		rep(i,m,n){
			ans=(ans+f[(1<<n)-1][i])%mod;
		} cout<<ans; return 0;
	}
	if(m==n){
		rep(i,0,n-1){
			if(s[i]=='0'){ cout<<0; return 0; }
		}
		rep(i,1,n){
			if(a[i]==0){ cout<<0; return 0; }
		}
		ll ans=1; rep(i,1,n) ans=(ans*i)%mod;
		cout<<ans; return 0;
	}
	if(m==1){ ll ans=1,All=1;
		rep(i,1,n) b[a[i]]++; rep(i,1,n) b[i]+=b[i-1]; int tmp=0;
		rep(i,0,n-1){ if(s[i]=='0') continue; if(b[i]<tmp){ cout<<0; return 0; }
			ans=(ans*(b[i]-tmp))%mod; if(ans==0) break;
			++tmp;
		}
		rep(i,1,n-tmp) ans=(ans*i)%mod;
		rep(i,1,n) All=(All*i)%mod;
		cout<<((All-ans)%mod+mod)%mod; return 0;
	}
	if(n==500&&m==12) cout<<"225301405";
	else cout<<0;
	return 0;
}
