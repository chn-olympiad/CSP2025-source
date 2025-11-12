#include<bits/stdc++.h>
using namespace std;
int a[5050];
int vis[5050];
int p[5050],idx=1;
int n;
int ans=0;
void dfs(int x,int k){
	if(x>k){
		int ma=0;
		int cnt=0;
		for(int i=1;i<=k;i++){
			ma=max(ma,p[i]);
			cnt+=p[i];
		}
		if(cnt>2*ma){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&p[x-1]<=a[i]){
			vis[i]=1;
			p[x]=a[i];
			dfs(x+1,k);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ma=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>ma*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		for(int i=3;i<=n;i++){
			dfs(1,i);
		}
		cout<<ans;
	}
	return 0;
}
