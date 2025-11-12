#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int u[10000000],v[10000000],w[10000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n;i++)
	{
		sum=sum+w[i];
	}
	cout<<sum;
	return 0;
}
