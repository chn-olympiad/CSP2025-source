#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool pd;
long long ans;
void dfs(int xb,bool pd,long long lo,int num,int ma)
{
	if(xb>n) return;
	if(pd)
	{
		if(lo+a[xb]>max(ma,a[xb])*2&&num+1>=3)
		{
			ans=(ans+1)%998244353;
//			cout<<lo+a[xb]<<"\n";
		}
		dfs(xb+1,1,lo+a[xb],num+1,max(ma,a[xb]));
		dfs(xb+1,0,lo+a[xb],num+1,max(ma,a[xb]));
	}
	else 
	{
		dfs(xb+1,1,lo,num,ma);
		dfs(xb+1,0,lo,num,ma);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) pd=1;
	}
	if(!pd)
	{
		for(int i=3;i<=n;i++)
		{
			long long x1=1,x2=1;
			for(int j=i;j>=1;j--) x1*=j;
			for(int j=n;j>=n-i+1;j--) x2*=j;
			ans=(ans+x2/x1)%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0,0);
	dfs(1,1,0,0,0);
	cout<<ans;
	return 0;
}
