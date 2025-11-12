#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define N 200010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue
#define pii pair<ll,ll>
#define fi first
#define se second

using namespace std;
const ll mod=998244353;
char s[510];
ll f[1<<18][18];
int c[510];
int n,m;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	For(i,1,n) cin>>s[i];
	For(i,1,n) cin>>c[i];
	if(m==n){
		int is=1;
		For(i,1,n) if(s[i]=='0') is=0;
		For(i,1,n) if(!c[i]) is=0;
		if(!is) cout<<0;
		else{
			ll ans=1;
			For(i,1,n) ans=ans*i%mod;
			cout<<ans;
		}
		return 0;
	}
	f[0][0]=1;
	For(S,0,(1<<n)-1){
		int cnt=__builtin_popcount(S);
		For(j,0,cnt){
			For(k,0,n-1){
				if(!((S>>k)&1)){
					f[S|(1<<k)][j+(cnt-j<c[k+1] && s[cnt+1]=='1')]=(f[S|(1<<k)][j+(cnt-j<c[k+1] && s[cnt+1]=='1')]+f[S][j])%mod;
				}
			}
		}
	}
	ll ans=0;
	For(i,m,n) ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}
