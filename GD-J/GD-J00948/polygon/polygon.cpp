#include <iostream>
using namespace std;

long long n,k,tap=3,a[5010],b[5010],vis[5010],s,mx,ans;
void dfs(int x)
{
	if(x>tap)
	{
		for(int i=1;i<=tap;++i)
			cout<<b[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i]) b[x]=a[i];
		vis[i]=1;
		dfs(x+1);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	if(n==3) cout<<1;
	while(tap<=n)
	{
		dfs(1);
		++tap;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
