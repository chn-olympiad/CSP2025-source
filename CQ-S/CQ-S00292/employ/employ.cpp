#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],f[1<<18][18];
char s[N];
int dfs(int state,int now){
	if(state==(1<<n)-1) return n-now>=m;
	if(~f[state][now]) return f[state][now];
	f[state][now]=0;
	for(int j=1;j<=n;++j) if(!(state&(1<<j-1))){
		if(s[__builtin_popcount(state)+1]=='0'||now>=c[j]) f[state][now]=(f[state][now]+dfs(state|(1<<j-1),now+1))%mod;
		else f[state][now]=(f[state][now]+dfs(state|(1<<j-1),now))%mod;
	}
	return f[state][now];
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	if(n<=18){
		memset(f,-1,sizeof(f));
		cout<<dfs(0,0)<<endl;
	} else if(m==n){
		for(int i=1;i<=n;++i) if(s[i]=='0'||c[i]==0){
			cout<<0<<endl;
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n;++i) ans=1ll*ans*i%mod;
		cout<<ans<<endl;
	} else cout<<0<<endl;
	return 0;
}
