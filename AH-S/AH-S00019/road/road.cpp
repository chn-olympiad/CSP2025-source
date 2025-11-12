#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
		int x,y,z;
		cin>>x>>y>>z;
		s+=z;
	}
	cout<<s;
	return 0;
}
