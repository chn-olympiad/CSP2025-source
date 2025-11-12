#include<bits/stdc++.h>

using namespace std;
vector<int> a(5005,0);
int mod=998244353;
long long dfs(int id,int smt,int mxt,int t){
	
	if(id<0 && smt>mxt*2 && t>=3) return 1;
	else if(id<0) return 0;
	long long ans=0;
	ans=(ans+dfs(id-1,smt,mxt,t))%mod;
	ans=(ans+dfs(id-1,smt+a[id],mxt,t+1))%mod;
	return ans%mod;
}
long long cnt_t(int n){
	long long ans=1;
	for(int i=0;i<n;i++) ans=(ans*2)%mod;
	ans-=n*(n-1)/2;
	ans-=n;
	ans--;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long tempc=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) tempc++;
	} 
	if(tempc==n){
		cout<<cnt_t(n);
		return 0;
	}
	sort(a.begin(),a.begin()+n);
	long long ans=0;
	for(int i=2;i<n;i++) ans=(ans+dfs(i-1,a[i],a[i],1))%mod;
	cout<<ans;
	return 0; 
}
