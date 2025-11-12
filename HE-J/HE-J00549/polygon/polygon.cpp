#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,a[5050],ret=0,num=0;
void dfs(int u,int l,int tot){
	num+=a[u];
	if(tot==l){
		if(num>2*a[u]){
			ret++;
			ret%=mod;
		}
		num-=a[u];
		return ;
	}
	for(int i=u+1;i<=n-l+tot+1;i++){
		dfs(i,l,tot+1);
	}
	num-=a[u];
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(j,i,1);
		}
	}
	cout<<ret;
	return 0;
}
