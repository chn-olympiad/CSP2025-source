#include <iostream>
#include <algorithm>
using namespace std;
long long n,ans;
long long a[10001];
long long N=998244353;
void dfs(int i,int max1,int z,int p)
{
	if(i>n)
	{
		if(z>max1*2&&p>=3)
		{
			ans=(ans+1)%N;
		}
		return ;
	}
	dfs(i+1,max1,z,p);
	dfs(i+1,a[i],z+a[i],p+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
