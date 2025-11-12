#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,flag=1;
int a[5005];
long long ans=0;
void dfs(int now,int sum,int Max){
	if(now>n){
		ans+=(Max*2<sum);
		ans%=mod;
		return ;
	}
	dfs(now+1,sum+a[now],max(Max,a[now]));
	dfs(now+1,sum,Max);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
	}
	if(flag){
		ans=2;
		for(int i=2;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans-=n*(n-1)/2%mod;
		ans=ans-1-n;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
