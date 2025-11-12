# include <bits/stdc++.h>
# define int long long
using namespace std;
const int mod=998244353;
int n,a[5500],vis[5500]={0},b[5500]={0},ans=0;
void dfs(int x,int zb,int k){
	if(x>zb){
		int sum=0,maxn=-1e9;
		for(int i=1;i<=zb;i++){
			sum+=b[i];
			maxn=max(b[i],maxn);
		}
		if(sum>maxn*2){
			ans++;
		}
		return;	
	}
	else{
		for(int i=k;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				b[x]=a[i];
				dfs(x+1,zb,i);
				vis[i]=0;
			}
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ccc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ccc++;
	}
	if(ccc==n){
		cout<<(ccc-2)%mod;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) dfs(1,i,1);
	cout<<ans%mod;
	return 0;
}
