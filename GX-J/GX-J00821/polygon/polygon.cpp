#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[100000],b[100000],ans1;
void dfs(int i,int sum,int m)
{
	for(int j=i+1;j<=n;j++)
	{
		
		if(m+1>=3&&sum>a[j]) ans=(ans+1)%998244353;
		dfs(j,sum+a[j],m+1);
	}
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
	    dfs(i,a[i],1);
	}
	cout<<ans;
	return 0;
}

