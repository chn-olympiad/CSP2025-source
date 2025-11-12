#include<bits/stdc++.h>
using namespace std;
const int N=5010;
#define int long long
const unsigned long long MOD=998244353; 
bitset<N> vis;
unsigned long long ans=0;
int a[N];
void dfs(int);
unsigned long long cal(int);
int n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag){
		for(int i=3;i<=n;i++)
			ans=(ans+cal(i))%MOD;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans%MOD;
	return 0;
}
unsigned long long cal(int m){
	if(m>=(n+1)/2)m=n-m;
	unsigned long long ret=1;
	for(int i=n,j=m;i>=(n-m+1);i--,j--)ret=ret*i/(j>=1?j:1);
	return ret;
}
void dfs(int p){
	if(p>n){
		int sum=0,maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i])sum+=a[i],maxx=max(maxx,a[i]);
		}
		if(sum>2*maxx)ans=(ans+1)%MOD;
		return ;
	}
	vis[p]=0;
	dfs(p+1);
	vis[p]=1;
	dfs(p+1);
	return ;
}
