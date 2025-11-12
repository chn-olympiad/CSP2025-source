#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,M=N<<1,inf=0x3f3f3f3f,mod=998244353;

inline int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48; c=getchar();}
	return x*f;
}
int n,m,ans;
int s[N],c[N];
int used[N],fact[N]={1};
void dfs(int x,int cnt1,int cnt2){
	if(n-cnt1<m) return;
	if(x>n){
		if(cnt2>=m) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		used[i]=1;
		if(s[x]==1&&c[i]>cnt1) dfs(x+1,cnt1,cnt2+1);
		else dfs(x+1,cnt1+1,cnt2);
		used[i]=0;
	}
}
void solve(){
	n=read(),m=read();
	bool ok=1;
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		char str; cin>>str;
		s[i]=str-48;
		if(!s[i]) cnt0++;
		else cnt1++;
		fact[i]=fact[i-1]*i%mod;
	}
	if(cnt1<m){ puts("0"); return; }
	if(!cnt0||m==n){ printf("%d",fact[n]); return; }
	for(int i=1;i<=n;i++) c[i]=read();
	dfs(1,0,0);
	printf("%d",ans%mod);
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}

