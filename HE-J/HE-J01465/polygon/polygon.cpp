#include<bits/stdc++.h>

using namespace std;

int n,a[5005];
long long ans;

inline void dfs(int p,int maxn,int sum){
	if(maxn*2<sum)++ans;
	for(int i=p+1;i<=n;++i){
		dfs(i,max(maxn,a[i]),sum+a[i]);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
//baoli 
