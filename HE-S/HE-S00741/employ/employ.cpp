#include<bits/stdc++.h>
#define ll long long
const ll mod = 998244353;
const int N = 5e2+10;
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
} string s; bitset<N>vis;
int p[N],c[N],n,m,ans;
bool check() {
	int tmp=0;
	for(int i=1;i<=n;i++) {
		if(tmp>=c[p[i]]) tmp++;
		else if(s[i]=='0') tmp++;
	} if(n-tmp>=m) return 1;
	else return 0;
}
void dfs(int dep) {
	if(dep==n+1) {
		ans=ans+check();
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		p[dep]=i; vis[i]=1;dfs(dep+1);vis[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=18) {
		dfs(1);
		cout<<ans;
	} else puts("0");
	return 0;
}
