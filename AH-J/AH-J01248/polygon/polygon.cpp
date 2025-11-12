#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
const int mod=998244353;
long long ans;
void dfs(int id,int sum,int mx){
	if(id==n+1){
		if(sum>mx*2)ans=(ans+1)%mod;
		return ;
	}
	int tmp=mx;
	dfs(id+1,sum+a[id],mx=max(mx,a[id]));
	dfs(id+1,sum,tmp);
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return 0;
	}
	return 1;
}
 long long C(int n,int m){
	if(n-m<m)m=n-m;
	long long sum1=1,sum2=1;
	for(int i=n;i>=n-m+1;i--){
		sum1=sum1*i%mod;
	}
	for(int i=m;i>=1;i--){
		sum2=sum2*i%mod;
	}
	return sum1/sum2%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check()){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
