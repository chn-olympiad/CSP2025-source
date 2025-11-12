#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,k,ans=0;
	cin>>n>>m>>k;
	for(long long i=1,a,b,c;i<=m;++i)
	{
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans<<"\n";
	return 0;
}
