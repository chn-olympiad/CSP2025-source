#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],ans=0;
void dfs(int x,int mx,int cnt,int sum){
	if(x>n){
		return;
	}
	if(cnt>=3&&sum>2*mx){
		ans++;
		ans%=998244353;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,max(mx,a[i]),cnt+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1,a[i]);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
