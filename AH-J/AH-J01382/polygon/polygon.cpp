#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int mod=998244353;
int n;
int temp;
int a[5005];
int c[5005][5005];
void dfs(int i,int maxx,int ans,int gs){
	if(i==n+1){
		if(ans>maxx*2&&gs>=3){
			temp++;
			temp%=mod;
			//~ cout<<ans<<" "<<maxx<<endl;
		}
		return;
	}
	else{
		dfs(i+1,max(maxx,a[i]),ans+a[i],gs+1);
		dfs(i+1,maxx,ans,gs);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	c[0][0]=1;
	for(int i=1;i<=5000;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		for(int i=3;i<=n;i++){
			temp=(temp+c[n][i]%mod)%mod;
		}
		cout<<temp;
	}
	else{
		dfs(1,0,0,0);
		cout<<temp;
	}
	return 0;
}
