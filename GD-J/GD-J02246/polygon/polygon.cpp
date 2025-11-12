#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int mod=998244353;
int a[N];
int c[N][N];
bool vis[1<<21];
int n,ans=0;
void init(){
	for(int i=1;i<=5000;i++){
		c[i][0]=c[i][i]=1;
	}
	for(int i=2;i<=5000;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j]%mod;
		}
	}
}
void dfs(int x,int sum,int maxn,int cnt,int v){
	if(cnt>=3&&sum>maxn*2&&!vis[v]){
		vis[v]=1;
		ans=ans+1%mod;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i],max(maxn,a[i]),cnt+1,v+1<<(i-1));
		dfs(i,a[i],a[i],1,1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		init();
		for(int i=3;i<=n;i++){
			ans=ans+c[n][i]%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,a[1],a[1],1,1);
	cout<<ans;
	return 0;
}
