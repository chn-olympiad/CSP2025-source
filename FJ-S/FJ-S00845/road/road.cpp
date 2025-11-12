#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,v;
		cin>>x>>y>>v;
		ans+=v;
	}
	cout<<ans;
	return 0;
}
