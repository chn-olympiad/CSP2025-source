#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
const int mod=998244353;
void dfs(int k,int cnt,int maxx,int sum){
	if(k==n+1){
		if(cnt>=3&&sum>maxx*2){
			ans++;	
			ans%=mod;
		}
		return;
	}
	//选或不选
	dfs(k+1,cnt,maxx,sum);
	dfs(k+1,cnt+1,max(maxx,a[k]),sum+a[k]); 
}
bool flag=true; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
			break;
		}
	}
	if(!flag){
		sort(a+1,a+1+n);
		dfs(1,0,0,0); 
		cout<<ans;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans-=n;
		ans%=mod;
		ans-=(n-1)*n/2;
		ans%=mod;
		cout<<(ans-1)%mod;
	}
	return 0;
}
