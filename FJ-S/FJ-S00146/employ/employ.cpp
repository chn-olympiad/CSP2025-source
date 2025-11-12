#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[501][501],c[1000001],n,m,ans=0,vis[1000001],mod=998244353;
string a;
void dfs(int step,int rs){
	if((n-rs)>=m&&step==n) ans++;
	ans%=mod;
	if(step==n) return;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(a[step]=='0') dfs(step+1,rs+1);
			if(a[step]=='1'){
				if(rs>=c[i]) dfs(step+1,rs+1);
				else dfs(step+1,rs);
			}
			vis[i]=0;
		}
	}
	return;
}
void solve1(){
	dfs(0,0);
}
void plzh(){
	for(int i=1;i<=500;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) f[i][j]=1;
			else f[i][j]=f[i-1][j-1]+f[i-1][j];
			f[i][j]%=mod;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int sum=0;
	cin>>n>>m>>a;
	for(int i=0;i<n;i++) cin>>c[i];
	if(n<=20){
		solve1();
		cout<<ans;
		return 0;
	}
	cout<<0;
} 
