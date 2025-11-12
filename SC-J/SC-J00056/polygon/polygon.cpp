#include<bits/stdc++.h>
using namespace std;
int a[5000+10];
int ans=0;
int n;
void dfs(int k,int ax,int sum,int m){
	if(k>n)return ;
	if(m+1>=3 && sum+a[k]>max(ax,a[k])*2)ans++;
	ans=ans%998244353;
	dfs(k+1,ax,sum,m);
	dfs(k+1,max(ax,a[k]),sum+a[k],m+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int MAX=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		MAX=max(MAX,a[i]);
	}
	if(MAX==1){
		ans=2;
		for(int i=2;i<=n;i++){
			ans=ans*2%998244353;
		}
		ans-=1;
		ans-=n;
		ans=(ans+998244353)%998244353;
		ans=ans-(n-1)*n/2;
		ans=(ans+998244353)%998244353;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}