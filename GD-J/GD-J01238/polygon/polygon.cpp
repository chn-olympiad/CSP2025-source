#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,mod=998244353,a[5005],f[5005][5005];
//s1代表选的木棍长度总和 s2代表选的木棍长度最大值 
void dfs(ll d,ll s1,ll s2){
	if(d==n+1){
		if(s1>2*s2) ans++;
		return;
	}
	dfs(d+1,s1+a[d],max(s2,a[d]));
	dfs(d+1,s1,s2);
}
void fun(){
	f[1][1]=1;
	for(int i=2;i<=n+1;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=f[i-1][j]+f[i-1][j-1];
			f[i][j]%=mod;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=30){
		dfs(1,0,0);
		ans%=mod;
		cout<<ans;
	}else{
		fun();
		for(int i=3;i<=n;i++){
			ans+=f[n+1][i+1];
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
