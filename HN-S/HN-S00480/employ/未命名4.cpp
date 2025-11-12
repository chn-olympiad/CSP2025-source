#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	//cout<<n;
	/*int a[n+5];
	int c[n+5];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>c[i];*/
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}cout<<ans;
	return 0;
}
