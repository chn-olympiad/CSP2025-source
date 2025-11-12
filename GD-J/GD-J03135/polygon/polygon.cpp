#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n,a[5010],ans;

void dfs(int k,int sum,int maxn,int l){
	if(k==n+1){
		if(sum>maxn*2&&l>=3) ans++;
		return ;
	}
	dfs(k+1,sum+a[k],a[k],l+1);
	dfs(k+1,sum,maxn,l);
}

int main( ){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
