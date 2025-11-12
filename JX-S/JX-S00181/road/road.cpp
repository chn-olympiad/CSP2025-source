#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,a,b,c,d;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b>>c>>d>>n;
	}
	cout<<ans;
	return 0;
}
