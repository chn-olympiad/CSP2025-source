#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
int n,a[5005];
long long ans=0;
void dfs(int i,int sum){
	if(i>n)return ;
	if(a[i]<sum&&i>=3){
		ans++;
		ans=ans%mod;
	}
	dfs(i+1,sum+a[i]);
	dfs(i+1,sum);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}