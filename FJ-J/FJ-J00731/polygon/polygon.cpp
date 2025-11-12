#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int a[10086];
int n,ans=0;
void dfs(int c,int zh,int zd){
	if(zh>zd*2&&zh>=3){
		ans++;
		ans%=MOD;
	}
	for(int i=c+1;i<=n;i++){
		dfs(i,zh+a[i],max(zd,a[i]));
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],a[i]);
	}
	
	cout<<ans;
	return 0;
}
