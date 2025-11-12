#include <iostream>
using namespace std;
const int mod=998244353;
int n,a[5001],ans=0;
void dfs(int nowo,int cnt,int sum,int maxx)
{
	if(nowo>=n+1)
	{
		if(sum>2*maxx&&cnt>=3) ans=(ans+1)%mod;
		return;
	}
	dfs(nowo+1,cnt+1,sum+a[nowo],max(maxx,a[nowo]));
	dfs(nowo+1,cnt,sum,maxx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
//[0,40];
//An Omega Oracle has been sent to hell by M28 with 100% damage!
//You were marked by lovely_CCF.
