#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans;
int a[505];
long long c[505],vis[505],b[505];
void dfs(long long x,long long step,int ng){
	if(x==n+1&&step>=m){
		ans++;
		ans%=mod;
		return;
	}
	if(step>=m){
		ans+=b[n-x+1];
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(a[x]==0){
			    dfs(x+1,step,ng+1);
			}else{
				if(c[i]<=ng){
					dfs(x+1,step,ng+1);
				}else{
					dfs(x+1,step+1,ng);
				}
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	b[1]=1;
	for(int i=2;i<=500;i++){
		b[i]=(b[i-1]*i)%mod;
	}
	dfs(1,0,0);
	printf("%lld",ans%mod);
	return 0;
} 
