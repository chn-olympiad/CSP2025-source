#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,s,w;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>w;
		s+=w;
	}
	cout<<s;
	return 0;
}
