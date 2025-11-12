#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int ans,n,a[N];
bool vis[N];
void dfs(int step,int maxn,int sum,int mw){
//	cout<<step<<' '<<maxn<<' '<<sum<<endl;
	if(step>=2){
		if(sum>maxn*2){
			ans=(ans+1)%mod;
		}
	}
	for(int i=mw-1;i>=1;i--){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,maxn,sum+a[i],i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<1;
		} 
		else{
			cout<<0;
		}
		return 0;
	}
	if(n<=20){
		for(int i=n;i>=1;i--){
			dfs(0,a[i],a[i],i);
		}
		cout<<ans;
		return 0;
	}
	else{
		int temp=1;
		for(int i=1;i<=n;i++){
			temp=temp*2%mod;
		}
		cout<<((temp-(n-1)*(n)/2%mod+mod)%mod-n-1+mod)%mod;
		return 0;
	}
}
/*
5
1 2 3 4 5
*/
