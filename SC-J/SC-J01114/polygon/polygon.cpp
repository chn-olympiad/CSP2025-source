#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[50000];
long long const mod=998244353;
void dfs(long long s,long long sum,long long maxx,long long cnt){
	if(cnt==n+1){
		if(s>=3&&sum>maxx*2){
			ans++;
		}
		return;
	}
	dfs(s,sum,maxx,cnt+1);
	dfs(s+1,sum+a[cnt],max(maxx,a[cnt]),cnt+1);
}
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans%mod;
	return 0;
}