#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
int n,ans,flag;
int a[N],dp[5005];
void dfs(int i,int sum,int id){
	if(id>=3&&sum>a[i]*2){
		ans=(ans+1)%998%244%353;
	}
	if(i>=n) return;
	for(int j=i+1;j<=n;j++){
		dfs(j,sum+a[j],id+1);
	}
	return;
}
void dfs2(int i,int sum,int id,int f){
	if(id>=3&&sum>a[i-1]*2&&f==0){
		ans=(ans+1)%998%244%353;
//		cout<<sum<<" "<<a[i-1]<<"\n";
	}
	if(i>n) return;
	dfs2(i+1,sum+a[i],id+1,0);
	dfs2(i+1,sum,id,1);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag++;
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]<=2*a[3]) cout<<0;
		else cout<<1;
		return 0;
	}
	if(flag==0){
		cout<<n*(n-1)/2;
		return 0;
	}
	if(n<=50){
		for(int i=1;i<=n-2;i++){
			dfs(i,a[i],1);
		}
		cout<<ans;
		return 0;
	}
	dfs2(0,0,0,0);
	cout<<ans/2;
	return 0;
}