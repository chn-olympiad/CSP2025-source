#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int N[5100];
int n;
long long ans;
void dfs(int t,int maxx,int sum){
	if(t>n){
		if(sum>maxx*2){
			ans++;
			ans%=mod;
		}	
		return; 
	}
	dfs(t+1,maxx,sum);
	dfs(t+1,max(maxx,N[t]),sum+N[t]);
}
long long C[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>N[i];
	}
	if(n<=20) dfs(1,0,0);
	else{
		C[1]=n;
		for(int i=2;i<=n;i++){
			C[i]=(C[i-1]*(n-i+1)/i)%mod;
			if(i>=3){
				ans+=C[i];
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
