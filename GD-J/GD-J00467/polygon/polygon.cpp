#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[6000],ans,ans1,vis[6000],p[6000];
bool f=0;
void dfs(int k,int nk,int maxn,int h){
	if(k>nk){
		if(h>2*maxn&&k>3) {
		ans1++,ans1%=mod;
	}
		return ;
	}
	for(int i=p[k-1]+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[k]=i;
			dfs(k+1,nk,max(maxn,a[i]),h+a[i]);
			vis[i]=0;
		}
	}
}
int c(int n,int m){
	int ans=1,r=1;
	for(int i=m;i>n;i--){
		ans=(ans*i)%mod;
	}
	for(int i=m-n;i>1;i--){
		r=(r*i)%mod;
	}
	return ans/r;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f){
		//cout<<1;
		for(int len=3;len<=n;len++){
			ans+=c(len,n);
			ans=ans%mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int nk=3;nk<=n;nk++){
		dfs(1,nk,0,0);
	}
	cout<<ans1%mod<<"\n"; 
	return 0;
}
