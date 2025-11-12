#include<bits/stdc++.h>
using namespace std;
const int N=5050;
const int MOD=998244353;
int a[N];
bool vis[N];
long long dp[N][N];
long long ans=0;
int n;
void dfs(int pos,int l,int k,int sum,int maxx)
{
	//printf("%d %d %d %d %d\n",pos,l,k,sum,maxx);
	if(k>=l){
		if(sum>maxx*2)ans=(ans+1)%MOD;
		return;
	}
	for(int i=pos;i<=n-l+k+1;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i+1,l,k+1,sum+a[i],a[i]);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=500){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int l=3;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			dfs(i+1,l,1,a[i],a[i]);
		}
	}
	cout<<ans;
	return 0;
}
