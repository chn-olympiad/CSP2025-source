#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,c[505],vis[505],p[505];
ll mod=998244353ll,ans;
char s[505];
void dfs(int x,int sum){
	if(x==n+1){
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x]=='1'&&c[i]>x-1-sum){
				if(sum==m-1) ans=(ans+p[n-x])%mod;
				else dfs(x+1,sum+1);			
			}
			else{
				dfs(x+1,sum);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*i%mod;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
