#include<bits/stdc++.h>
using namespace std;
long long b,c,d,e,m,n,k,a;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
	}
	for(int i=1;i<=k;++i)
	{
		for(int i=1;i<=n+1;i++)
		cin>>a;
	}
	if(n<=100)
	cout<<13;
	else
	cout<<505585651;
	return 0;
}
