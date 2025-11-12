#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],ans,sum;
bool dp[2500005][505];
bool f[2100000],chen[5005];
int cl(){
	int zz=0;
	for(int i=1;i<=n;i++){
		if(chen[i]){
			zz++;
		}
		zz*=2;
	}
	return zz;
}
void dfs(int x,int y,int sum,int maxx){
	if(y>=3){
		if(sum>maxx*2&&f[cl()]==0){
			f[cl()]=1;
			ans++;
			ans%=mod;
		}
	}
	if(x>n){
		return ;
	}
	chen[x]=1;
	dfs(x+1,y+1,sum+a[x],max(maxx,a[x]));
	chen[x]=0;
	dfs(x+1,y,sum,maxx);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--){
			for(int k=1;k<=n;k++){
				dp[j][k]=dp[j][k]||dp[j-a[i]][k-1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2*a[i]+1;j<=sum;j++){
			for(int k=3;k<=n;k++){
				if(dp[j][k]){
					ans++;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
