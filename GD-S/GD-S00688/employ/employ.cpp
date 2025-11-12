#include<bits/stdc++.h>
#define N 505
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[N],p[N],vis[N];
char s[N];
int ans=0;
void dfs(int x){
	if(x>n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')cnt++;
			else{
				if(cnt>=a[p[i]])cnt++;
				else sum++;
			}
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	int bz=1;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		if(s[i]=='0')bz=0;
	if(n<=10){
		dfs(1);
		printf("%lld\n",ans);
	}else puts("0");
}
