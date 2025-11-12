#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,maxx,a[5005];
ll ans;
int dfs(int p,int sum,int maxx){
	if(p>n) return 0;
	int ans=(sum>maxx*2);
	for(int i=p+1;i<=n;i++)
		(ans+=dfs(i,sum+a[i],max(maxx,a[i])))%=mod;
	return ans%mod;
}
int f[5005][2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(n<=20){cout<<dfs(0,0,0)%mod;return 0;}
	if(maxx==1){
		f[3][0]=3,f[3][1]=1;
		for(int i=4;i<=n;i++){
			f[i][0]=i*(i-1)/2%mod;
			f[i][1]=(f[i-1][1]*2%mod+f[i-1][0])%mod;
		}
		cout<<f[n][1]%mod;
		return 0;
	}
	cout<<dfs(0,0,0)%mod;
	return 0;
}//AKIOI!!! 
