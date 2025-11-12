#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
//int b[5005];
//int mx[5005];
int ans;
int vis[5005];
int mod=998244353;
int cnt;
void dfs(int k,int cnt,int sum,int mx,int last){
	if(cnt>=3&&sum>mx*2&&cnt!=last){
		ans++;
//		cout<<cnt<<endl;
//		for(int i=1;i<=cnt;i++) cout<<vis[i]<<' ';
//		cout<<endl<<ans<<endl;
	} 
	ans%=mod;
	if(k>n||cnt>n) return;
//	cout<<a[k]<<' ';
	vis[cnt+1]=a[k];
	dfs(k+1,cnt+1,sum+a[k],max(mx,a[k]),cnt);
	dfs(k+1,cnt,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(cnt==n){
		cout<<(n-1)*(n-2)/2;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<ans%mod;
	return 0;
}

