#include<bits/stdc++.h>
using namespace std;
const int N=500,mod=998244353;
int n,m,a[N],c[N],vis[N],ans,fac[N];
void dfs(int x,int y){
	if(y==m){
		ans=(1ll*ans+fac[n-x+1])%mod;
		return;
	}
	if(x>n)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[x]&&x-1-y<c[i])dfs(x+1,y+1);
			else dfs(x+1,y);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
//	sort(c+1,c+n+1);
	dfs(1,0);
	cout<<ans;
	return 0;
}
