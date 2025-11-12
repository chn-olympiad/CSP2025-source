#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,mod=998244353;
int n,m,s[maxn],c[maxn];
long long ans;
int used[maxn];
int fa=1;
string ss;
void in() {
	cin>>n>>m;
	cin>>ss;
	ss=" "+ss;
	for(int i=1; i<=n; i++) {
		s[i]=ss[i]-'0';
		if(s[i]==0)fa=0;
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
}
void dfs(int x,int cnt,int f) {
	if(x==n+1) {
		ans=(ans+(cnt>=m))%mod;
		return;
	}

	for(int i=1; i<=n; i++) {
		if(used[i])continue;
		used[i]=1;
		dfs(x+1,cnt+((f<c[i])&&(s[x]==1)),f+(s[x]==0||(f>=c[i])));
		used[i]=0;
	}
}
void work() {
	ans=1;
	for(long long i=2; i<=n; i++) {
		ans=(1ll*ans*i)%mod;
	}
}
int main() {
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	in();
	if(fa) {
		work();
	} else {
		dfs(1,0,0);
	}
	cout<<ans%mod<<endl;
	return 0;
}
