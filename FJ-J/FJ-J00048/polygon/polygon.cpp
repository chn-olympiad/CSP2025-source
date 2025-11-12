#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],ans,ma=0,mi=5001;
//void dfs(int x,int l,int ma,int lt)
//{
////	cout<<l<<' '<<ma<<' '<<lt<<endl;
//	if(x>=3&&l>ma*2)ans=(ans+1)%998244353;
//	for(int i=lt+1;i<=n;i++)
//	{
//		if(!vis[i])
//		{
////			cout<<x<<":"<<i<<' ';
//			vis[i]=1;
//			dfs(x+1,l+a[i],max(ma,a[i]),i);
////			cout<<endl;
//			vis[i]=0;
//		}
//		
//	}
//}
void dfs(int x,int i,long long ma,int l)
{
	if(i==n+1)
	{
		if(x>=3&&l>ma*2)
		{
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(x+1,i+1,max(ma,a[i]),l+a[i]);
	dfs(x,i+1,ma,l);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
//	dfs(1,0,0,0);
	dfs(0,1,0,0);
	cout<<ans%998244353;
	return 0;
}

