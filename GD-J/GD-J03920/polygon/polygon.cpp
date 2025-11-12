#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
bool vis[5005];
bool A=true;
long long ans=0;
void dfs(int cnt,long long sum,int maxx,int i){
	if(cnt>=3&&sum>maxx*2)ans=(ans+1)%mod;
	for(;i<min(n,n-3+cnt+1);i++){
		if(!vis[i]){
			vis[i]=true;
//			cout<<a[i]<<" ";
			dfs(cnt+1,sum+a[i],max(maxx,a[i]),i+1);
			vis[i]=false;
		}
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)A=false;
	}
	if(A){
		ans=1;
		for(int i=4;i<=n;i++){
			ans=(((ans*2)%mod)+((n*(n-1)/2)%mod))%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
	dfs(0,0,-1,0);
	cout<<ans;
	return 0;
}
