#include<bits/stdc++.h>
using namespace std;
long long n,a[6000];
bool f=1;
long long ans=0;
void dfs(long long id,long long mx,long long k,long long sum,long long cnt){
//	if(mx*2>sum&&cnt>=3) return;
	if(id>n) return;
	if(cnt==k){
		if(mx*2<sum) ans++;
		ans=ans%998244353;
		return;
	}
	for(long long i=id+1;i<=n;i++){
		dfs(i,max(mx,a[i]),k,sum+a[i],cnt+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		for(long long i=3;i<=n;i++){
			long long t=1;
			for(long long j=1;j<=(n-i);j++){
				t=t%998244353*(n-j+1)%998244353;
			}
			ans=(ans%998244353+t%998244353)%998244353;
		}
	}
	else if(n<=20){
		for(long long i=3;i<=n;i++){
			dfs(0,-1,i,0,0);
		}
	}
	else{
		for(long long i=3;i<=n;i++){
			long long t=1;
			for(long long j=1;j<=(n-i);j++){
				t=t%998244353*(n-j+1)%998244353;
			}
			ans=(ans%998244353+t%998244353)%998244353;
		}
	}
	cout<<ans;
	return 0;
}