#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
long long n,m,ans,a[N],b[N],bj[N],sum,sum1;
string s;
void dfs(int i)
{
	if(i==n+1)
	{
		sum1=0;
		for(int j=1;j<=n;++j)
			if(sum1>=a[b[j]]||s[j-1]=='0') ++sum1;
		if(n-sum1>=m)
			++sum;
		sum%=mod;
		return;
	}
	for(int j=1;j<=n;++j)
		if(!bj[j]) bj[j]=1,b[i]=j,dfs(i+1),b[i]=0,bj[j]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
		if(s[i]=='1')
			 ++sum;
	if(sum==n)
	{
		ans=1;
		for(int i=1;i<=n;++i)
			ans=(ans*i)%mod; 
		cout<<ans<<'\n';
	}
	else{
		sum=0;
		dfs(1);
		cout<<sum<<'\n';
	}
	return 0; 
 } 
