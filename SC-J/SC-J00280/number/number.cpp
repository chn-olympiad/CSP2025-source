#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,cnt;
int a[5005];
bool vis[5005];
void dfs(int k,int sum,int mx,int eg,int tot){
	if(tot==eg){
		if(sum>2*mx) cnt++;
		cnt%=mod;
		return ;
	}
	for(int i=k+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,sum+a[i],max(mx,a[i]),eg,tot+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int sum=0,mx=0;
		for(int i=1;i<=n;i++) sum+=a[i],mx=max(mx,a[i]);
		if(sum>2*mx) cout<<1;
		else cout<<0;
		return 0;
	}
	int sum=0,mx=0;
	for(int i=1;i<=n;i++) sum+=a[i],mx=max(mx,a[i]);
	if(mx==1){
		int tot=1,m=1;
		for(int i=1;i<=n;i++) m*=i;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++) tot*=j;
			for(int j=1;j<=n-i;j++) tot*=j;
			cnt=(cnt+m/tot)%mod;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(0,0,0,i,0);
	}
	cout<<cnt%mod;
	return 0;
}
/*5
1 2 3 4 5*/