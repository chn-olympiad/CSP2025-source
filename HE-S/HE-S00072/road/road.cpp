#include<bits/stdc++.h>
using namespace std;
int n,m,d,k,w;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m;
	cin>>n;
	cin>>k;
    for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
				w=j*i;
	    		cout<<i;
				cout<<j;
		}	
	}	
	return 0;
}
