#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],ans;
int sum(int st,int ed){
	int res=0;
	for(int i=st;i<=ed;i++) res+=a[i];
	return res;
}
void dfs(int pos,int asum,int maxx){
	if(pos>n){
		if(asum>maxx*2) ans++;
		ans%=mod;
		return;
	}
	dfs(pos+1,asum,maxx);
	maxx=max(maxx,a[pos]);
	dfs(pos+1,asum+a[pos],maxx);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	ans%=mod;
	cout<<ans;
	return 0;
}

