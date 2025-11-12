//road.cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,min=0x3f3f3f3f,k,p;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>p>>p>>p;
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++) cin>>p;
		if(x<min) min=x;
	}
	cout<<min;
	return 0;
}
