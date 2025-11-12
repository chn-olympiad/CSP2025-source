#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,u[1000100],v[1000010],w[1000100],c[1000010],a[1000010],ans=0;
map<string,int> mp;
string ss;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ss=u[i]+" "+v[i];
		map[ss]=min(map[ss],w[i]);
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
	}
	for(int i=0;i<m;i++)
	{
		ss=u[i]+" "+v[i];
		ans+=map[ss];
	}
	cout<<ans;
	return 0;
}
