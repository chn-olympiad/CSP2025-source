#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a;
		cin>>a;
		cin>>a;
		ans+=a;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a;
		}
	}
	cout<<ans<<endl;
	return 0;
}
