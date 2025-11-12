#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define arr(a) array<int,(a)>
#define cases(_) while((_)--) solve()
#define RE return puts("0"),void();
using namespace std;
const int N=505,mod=998244353;
int _=1,n,m,a[N],c[N];
ll ans;
char s[N];
inline void add(ll& x,int y){x=(x%mod+y%mod+mod)%mod;}
void solve(){
	scanf("%d%d%s",&n,&m,s+1);
	rep(i,1,n) scanf("%d",&c[i]),a[i]=i;
	do{
		int cnt=0;
		rep(i,1,n) if(s[i]=='1' && i-1-cnt<c[a[i]]) cnt++;
		if(cnt>=m) add(ans,1);
	}while(next_permutation(a+1,a+n+1));
	printf("%lld\n",ans);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	// scanf("%d",&_);
	cases(_);
	return 0;
}
