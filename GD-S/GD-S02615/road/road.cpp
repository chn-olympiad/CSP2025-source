#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	if(k==0)
	{
		int res=0; 
		for(int i=1;i<=n;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			res+=w;
		}
		cout<<res;
	}
}
