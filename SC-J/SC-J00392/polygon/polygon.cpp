#include <bits/stdc++.h>
using namespace std;
int a[6000];
int ans=0,n;
void dfs(int st,int sum,int mx,int cnt){
	if(cnt>=3&&sum>2*mx){
		ans++;
		ans=ans%998244353;
	}
	for(int i=st;i<=n;i++){
		dfs(i+1,sum+a[i],max(mx,a[i]),cnt+1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}