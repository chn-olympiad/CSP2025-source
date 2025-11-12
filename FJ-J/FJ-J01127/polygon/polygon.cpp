#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans,jc[5020];
int n,a[5020],b[5020],sum;
bool flag=1;
void dfs(int num,int bian,int cnt)
{
	if(cnt==bian)
	{
		if(sum>b[cnt]*2)
		{
			ans++;
			ans%=998244353;
		}
		return; 
	}
	if(num>n)
		return; 
	b[cnt+1]=a[num];
	sum+=a[num]; 
	dfs(num+1,bian,cnt+1);
	b[cnt+1]=0;
	sum-=a[num];
	dfs(num+1,bian,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			flag=0;
	}
	if(flag)
	{
		jc[1]=ans=1;
		for(int i=2;i<=n;i++)
			jc[i]=jc[i-1]*i%mod;
		for(int i=3;i<n;i++)
			ans+=jc[n]/jc[i]/jc[n-i],ans%=mod;
		cout<<ans;
		return 0; 
	}
	sort(a+1,a+n+1); 
	for(int bian=3;bian<=n;bian++)
	{
		dfs(1,bian,0);
	}
	cout<<ans;
}
