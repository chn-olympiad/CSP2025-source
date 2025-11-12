#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans=0,c=1;;
void dfs(int dep,int maxn,int cnt,int k){
	if(k+n-dep+1<3)return ;
	if(dep>n){
		if(cnt>maxn*2)ans++;
		ans%=998244353;
		return ;
	}
	dfs(dep+1,a[dep],cnt+a[dep],k+1);
	dfs(dep+1,maxn,cnt,k);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=500){
		for(int i=1;i<=n;i++){
			c=(c*(n-i+1)%998244353)/(i%998244353);
			c%=998244353;
			if(i>=3)ans+=c;
			ans%=998244353;
		}
	}
	else{
		sort(a+1,a+n+1);
		dfs(1,0,0,0);
	}
	cout<<ans%998244353;
	return 0;
}

