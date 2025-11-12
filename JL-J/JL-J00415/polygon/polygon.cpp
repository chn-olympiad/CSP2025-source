#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];
int n,ans=0;
void dfs(int l,int t,int s){
	if(t>=3&&a[l]*2<s){
		ans++;
	}for(int i=l+1;i<n;i++){
		dfs(i,t+1,s+a[i]);
	}
}signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=0;i<n;i++){
		dfs(i,1,a[i]);
	}cout<<ans%998244353;
	return 0;
}
