#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long MOD=998244353;
int n,a[5005],ans;
void dfs(int x,int s,int sum)
{
	if(s>=3)
	{
		if(sum>a[x]*2)
		{
			ans++;
			ans%=MOD;
		}
	}
	if(x==n)
	{
		return;
	}
	for(int i=x+1;i<=n;i++)
    {
        dfs(i,s+1,sum+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<ans%MOD;
}