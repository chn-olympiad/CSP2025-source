#include<bits/stdc++.h>
using namespace std;
int n,a[50005],t[100005];
const long long mod=998244353;
long long ans=0;
void dfs(int dis,int sum,int maxn,int js){
	if(dis==n+1){
		if(sum>maxn*2&&js>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(dis+1,sum+a[dis],a[dis],js+1);
	dfs(dis+1,sum,maxn,js);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=-1;
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
