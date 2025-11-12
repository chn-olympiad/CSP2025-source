#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],ans,mod=998244353,qw;
void dfs(int x,int ma,int zh,int sum)
{
	if(zh>ma*2&&sum>=3) ans++;
	ans=ans%mod;
	for(int i=x;i<=n;i++)
	{
		dfs(i+1,max(ma,a[i]),zh+a[i],sum+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=26) dfs(1,0,0,0);
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1) ans=2;
			else ans*=2;
			ans=ans%mod;
		}
		ans=ans-n-(n-1)*n/2-1;
		ans=(ans%mod+mod)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
