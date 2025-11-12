#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	long z=0;
	int n,m,k,a;
	cin>>n>>m>>k;
	int b[n];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(j==2)
			{
				cin>>b[i];
			}
			cin>>a;		
		}
	}
	for(int i=0;i<k;++i)
	{
		for(int j=0;j<n+1;++j)
		{
			cin>>a;
		}
	}
	sort(b,b+n);
	for(int i=0;i<n/2;++i)
	{
		z+=b[i];
	}
	
	return 0;
}
