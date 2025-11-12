#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
		long long a,b,c,e,d=0;
		cin>>a>>b>>c;
		for(int i=1;i<=b;i++)cin>>e;
		for(int i=1;i<=c;i++)
		{
			for(int j=1;j<=a+1;j++)
			{
				cin>>e;
				d+=e;
			}
		}
		cout<<e;
	return 0;
}
