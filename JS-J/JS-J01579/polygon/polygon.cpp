#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
long long ans=0;
int vis[100100];
void dfs(int pos){
	if(pos==n+1){
		int num=0,mx=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				num++;
				mx=a[i];
			}
		}
		if(sum-mx>mx && num>2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=0;i<=1;i++){
		vis[pos]=i;
		dfs(pos+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag==1){
		cout<<(1ll*((1ll*2)<<n)-1-n-n*(n-1)/2)%998244353;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}
