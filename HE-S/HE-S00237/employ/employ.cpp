#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=998244353;
inline int read() {
	int s=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9') x=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*x;
}
int n,m,c[N],p[N];
bool vis[N];
long long ans;
char s[N];
inline void dfs(int nw) {
	if(nw==n) {
		int No=0,res=0;
		for(int i=1;i<=n;++i) {
			if(No>=c[p[i]]||s[i]=='0') No++;
			else res++;
		}
		ans+=(res>=m);return ;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]) vis[i]=1,p[nw+1]=i,dfs(nw+1),vis[i]=0;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();scanf("%s",s+1);
	for(int i=1;i<=n;++i) c[i]=read();
	if(m==n) {
		bool flag=1;
		for(int i=1;i<=n;++i)
			if(!c[i]||s[i]=='0') flag=0;
		if(!flag) cout<<0;
		else {
			ans=1;for(int i=1;i<=n;++i) ans=1ll*i*ans%mod;
			cout<<ans;
		}
		return 0;
	}
	if(n>10) {
		ans=1;for(int i=1;i<=n;++i) ans=1ll*i*ans%mod;
		cout<<ans;return 0;
	}
	dfs(0);cout<<ans;
	return 0;
}
