#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans;
void dfs(int pos,int mlo,int sum,int m){
	if(pos==n+1){
		if(m>=3&&sum>mlo*2)ans=(ans+1)%998244353ll;
		return;
	}
	dfs(pos+1,mlo,sum,m);
	dfs(pos+1,max(mlo,a[pos]),sum+a[pos],m+1);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
