#include<bits/stdc++.h>
# define Maxn 505
# define ll long long
# define mod 9982444353
using namespace std;
bool vis[Maxn];
int n,m,s[Maxn],c[Maxn];
int f[Maxn],d[Maxn];
char ch;
ll ans;
void dfs(int t,int w) {
	if(w+d[t]<m) return ;
	if(t>n) {ans=(ans+1<mod?ans+1:ans+1-mod);return ;}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			f[t]=i;
			if(t-1-w>=c[i]) dfs(t+1,w);
			else dfs(t+1,w+s[t]);
			vis[i]=0;
		}
	}
}
void solve() {
	bool bz=0;
	for(int i=1;i<=n;i++) {
		if(s[i]!=1)
		{bz=1;break;}
	}
	if(bz) {printf("0\n");exit(0);}
	for(int i=1;i<=n;i++) {
		if(c[i]==0)
		{bz=1;break;}
	}
	if(bz) {printf("0\n");exit(0);}
	ans=1;
	for(int i=1;i<=n;i++)
	ans=1ll*i*ans%mod;
	printf("%lld\n",ans);
	exit(0);
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	cin>>ch,s[i]=ch-'0';
	for(int i=n;i>=1;i--)
	d[i]=d[i+1]+s[i];
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
	if(m==n) solve();
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
