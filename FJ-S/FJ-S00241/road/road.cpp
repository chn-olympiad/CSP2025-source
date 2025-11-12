#include <bits/stdc++.h>
#define ll long long
using namespace std;
int w[1000005];
int main()
{
    ll n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		ll ans=0;
		memset(w,0,sizeof(w));
		int u,v;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w[i];
			sort(w+1,w+m+1);
			for(int i=1;i<=n-1;i++)
			    ans+=w[i];
		}
		cout<<ans;
	}
	return 0;
}
