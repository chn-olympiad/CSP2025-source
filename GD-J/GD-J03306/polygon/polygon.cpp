#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e3+5,mod=998244353; 
int n,ret,a[N],jc[N];
bool vis[N];
void dfs(int x){
	if(x==n+1)
	{
		int sum=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)continue;
			sum+=a[i],num=max(num,a[i]);
		}
		if(sum>2*num)ret++,ret%=mod;
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
bool check(){
	for(int i=1;i<=n;i++)if(a[i]!=1)return 0;
	return 1;
}
int ksm(int x,int y,int mod){
	int ret=1;
	while(y!=0)
	{
		if(y%2==1)ret*=x,ret%=mod;
		y/=2;
		x*=x,x%=mod;
	}
	return ret;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20)
	{
		dfs(1);
		cout<<ret;
		return 0;	
	} 
	if(check()==1)
	{
		jc[0]=1;
		for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
		for(int i=3;i<=n;i++)
		{
			ret+=jc[n]*ksm(jc[i]*jc[n-i]%mod,mod-2,mod)%mod,ret%=mod;
		}
		cout<<ret;
		return 0;
	}
	return 0;
}

