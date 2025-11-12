#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m,d[5005],P=1,mod=998244353;
int dfs(int x,int sum,int ma)
{
/*	for(int i=1;i<P;i++) cout<<"| ";
	cout<<"> in dfs("<<x<<","<<sum<<","<<ma<<")                   --- "<<P-1<<" chose:"<<x<<"\n";
*/	P++;
	int ans=0;
	for(int i=x+1;i<=n;i++)
		ans=ans+dfs(i,sum+a[i],max(ma,a[i]))%mod;
	ans=(ans+(sum>ma*2))%mod;
	P--;
/*	for(int i=0;i<P;i++) cout<<"| ";
	cout<<"^turn back dfs("<<x<<","<<sum<<","<<ma<<")="<<ans<<"\n";
*/	return ans%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d",dfs(0,0,0));
	return 0;
}
