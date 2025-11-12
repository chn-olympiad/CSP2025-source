#include<bits/stdc++.h>
using namespace std;
const int N=5e3+3,mod=998244353;
#define ll long long
ll n,k,g[N],flag,ans;
ll dp[50003];
vector<int>e1,e2;
ll C(int n,int m){
	ll sumn=1,summ=1,sum=1;
	for(int i=1;i<=n;i++)(sumn*=i)%=mod;
	for(int i=1;i<=(n-m);i++)(summ*=i)%=mod;
	for(int i=1;i<=m;i++)(sum*=i)%=mod;
	return sumn/summ/sum;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>g[i],flag+=g[i];
	if(flag==n){
		for(int i=3;i<=n;i++){
			(ans+=C(n,i))%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(g+1,g+1+n);
	for(int i=1;i<=n+1;i++){
		for(int j=flag;j>=3;j--){
			if(dp[j]&&j+g[i]>2*g[i]){
				(dp[j+g[i]]+=dp[j])%=mod;
			}
		}
		for(auto j:e2)if(j+g[i]>2*g[i])dp[j+g[i]]+=1;
		for(auto j:e1)e2.push_back(j+g[i]);
		e1.push_back(i);
	}
	for(int i=3;i<=flag;i++)ans+=dp[i];
	cout<<ans%mod/2;
	return 0;
}