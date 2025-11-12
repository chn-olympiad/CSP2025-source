#include<bits\stdc++.h>
using namespace std;
int n,a[5005],ans;
int ma[5005][5005];
const int mod=998244353;
void dfs(int he,int x)
{
	if(he>2*a[x])
		ans=(ans+1)%mod;
	for(int i=x+1;i<=n;i++)
	{
		int flag=0;
		if(he>a[i])
			flag=1;
		else
			for(int j=i;j<=n;j++)
			{
				if(he+ma[i][j]>2*a[j])
				{
					flag=1;
					break;
				}
			}
		if(flag)
			dfs(he+a[i],i);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int he=0;
		for(int j=i;j<=n;j++)
		{
			he+=a[j];
			ma[i][j]=he;
		}
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
