#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt;
int a[500005];
void dfs(int x,int nn,int s,int k,int xx){
	if(x>nn){
		if(s>xx&&k>1) cnt=(cnt+1)%998244353; 
		return;
	}
	dfs(x+1,nn,s+a[x],k+1,xx);
	dfs(x+1,nn,s,k,xx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cnt=0;
		dfs(1,i-1,0,0,a[i]);
		ans=(ans+cnt)%998244353;
	}
	cout<<ans;
	return 0;
}
