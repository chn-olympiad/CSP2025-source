#include<bits/stdc++.h>
using namespace std;
int a[1001001],vis[1001001],n;
int cnt;
void dfs(int m,int l,int mx,int j){
	if(m>=3&&l>2*mx){
		cnt++;
		cnt%=998244353;
	}if(m==n)return ;
	for(int i=j;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(m+1,l+a[i],max(mx,a[i]),i);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,1);
	cout<<cnt;
	return 0;
}
