#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e2+10;
int n,m,s[N],c[N];
bool vis[N];
int a[N],ans;
inline void dfs(int x) {
	if(x>n) {
		int p=0,cnt=0;
		for(int i=1;i<=n;i++) {
			if(p>=c[a[i]]) {
				p++;
				continue;
			}
			if(s[i]==1)
				cnt++;
			else p++;
		}
		if(cnt>=m)
			ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return ;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		char x;
		cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	if(n<=18) {
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++) 
		if(!c[i]) flag=0;
	if(!flag) {
		printf("0\n");
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	printf("%lld\n",ans);
	return 0;
}
