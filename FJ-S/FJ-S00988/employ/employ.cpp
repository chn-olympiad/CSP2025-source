#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,ans1,ans2;
string hard;
long long ans,jc[520];
int p[520];
int work[520];
bool flag=1,vis[520];
void dfs(int step)
{
	if(ans2>n-m)
		return;
	if(step==n+1)
	{
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bool flag=1;
			vis[i]=1;
			work[step]=i;
			if(hard[step-1]=='1'&&ans2<p[work[step]])
				ans1++;
			else
				ans2++,flag=0;
			dfs(step+1);
			vis[i]=0;
			work[step]=0;
			if(flag)
				ans1--;
			else
				ans2--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>hard;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]=='0')
			flag=0;
	}
	if(flag){
		jc[1]=1;
		for(int i=2;i<=n;i++)
			jc[i]=jc[i-1]*i%mod;
		ans=jc[n];
	}
	else
		dfs(1);
	cout<<ans;
}
