#include<bits/stdc++.h>
#include<queue>
#define int long long
using namespace std;
int n,m,k,ans,a,b,c;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	return 0;
}
