#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int v[5005];
int ans=0;
void dfs(int x){
	if(x==n+1){
		int sum=0;
		int maxx=0;
		for(int i=1;i<=n;i++){
			if(v[i]==1){
				maxx=max(maxx,a[i]);
				sum+=a[i];
			}
		}
		if(sum>maxx*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	v[x]=1;
	dfs(x+1);
	v[x]=0;
	dfs(x+1); 
}
bool pd1(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return false;
	}
	return true;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(pd1()){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans-=1+n+n*(n-1)/2;
	}else dfs(1);
	cout<<ans%mod<<endl;
	return 0;
}

