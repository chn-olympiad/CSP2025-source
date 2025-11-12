#include<bits/stdc++.h>
using namespace std;
const int mx=5005;
const int mod=998244353;
int vis[mx],s[mx],n,b[mx];
long long ans;
void dfs(int step,int a[],int k,int st){
	if(step==k){
		int maxx=0,sum=0;
		for(int i=1;i<=k;i++){
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>maxx*2){
		//	for(int i=1;i<=k;i++){
		//		cout<<a[i]<<" ";
		//	}
		//	cout<<'\n';
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=st;i<=n;i++){
		if(!vis[i]){
			a[step+1]=s[i];
			vis[i]=1;
			dfs(step+1,a,k,i+1);
			vis[i]=0;
		}
	}
	return;
}
long long pw(int x){
	long long re=1;
	for(int i=n;i>=n-x+1;i--)re*=i;
	return re;
}
long long pow(int x){
	long long re=1;
	for(int i=1;i<=x;i++)re*=i;
	return re;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!=1)flag=1;
	}
	if(flag==0){
		for(int i=3;i<=n;i++){
			ans+=pw(i)/pow(i);
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof vis);
		memset(b,0,sizeof b);
		dfs(0,b,i,1);
	}
	cout<<ans%mod;
	return 0;
}