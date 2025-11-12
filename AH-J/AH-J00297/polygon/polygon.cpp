#include<bits/stdc++.h>
using namespace std;
long long ans=0,cnt=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==1) cout<<0;
	if(n==2) cout<<0;
	if(n==3) 
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x+y+z>z*2) cout<<1;
	}
	
	return 0;
}
