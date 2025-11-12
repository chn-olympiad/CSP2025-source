#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int zz=0;zz<t;zz++)
	{
		int n,x,y,z,sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>z;
			sum+=max(max(x,y),z);
		}
		cout<<sum<<'\n';
	}
}
