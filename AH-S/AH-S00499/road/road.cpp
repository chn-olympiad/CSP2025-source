#include <bits/stdc++.h>
using namespace std;
long long u[1000010],v[1000010],w[1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,num=0;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		num+=w[i];
	}
	cout<<num;    
	return 0;
}
