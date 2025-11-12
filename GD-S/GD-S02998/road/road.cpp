#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k,u[N],v[N],w[N],tot;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		tot+=w[i];
	}
	cout<<tot;
	return 0;
}
