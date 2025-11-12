#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,x,num,a[100010],k,k1,l,r,y,mid,f[100010],mod=998244353;
struct cc{
	long long x,y;
}dp[5010][5010];
void dfs(int k,int x,int y,int num,int yy){
	if(k==x&&y*2<num) ans++;
	for(int i=yy+1;i<=n;i++) dfs(k,x+1,a[i],num+a[i],i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int lo=3;lo<=n;lo++) dfs(lo,0,0,0,0);
	cout<<ans%mod;
}
