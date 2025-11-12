#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long maxn=5005,p=998244353;
long long n,a[maxn],maxai=1,ans=0;
bool vis[maxn];
void dfs(long long x,long long maxx,long long sum,long long num){
	if(x>n) return ;
//	for(long long i=1;i<=n;i++) cout<<vis[i]<<" ";
//	cout<<endl;
	if(sum>maxx*2&&num>=3) ans++,ans%=p;
	for(long long i=x;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=true;
		dfs(i,max(maxx,a[i]),sum+a[i],num+1);
		vis[i]=false;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;++i) cin>>a[i],maxai=max(maxai,a[i]);
	if(n==3){
		if(a[1]+a[2]+a[3]>maxai*2) cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n-2;++i){
		vis[i]=true;
		dfs(i,a[i],a[i],1);
		vis[i]=false;
	}
	cout<<ans;
	return 0;
}/*
5
1 2 3 4 5
*/