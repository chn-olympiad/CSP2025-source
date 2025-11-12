#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			int z1,z2,z3;
			cin>>z1>>z2>>z3;
			sum+=max(z1,z2,z3)l;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
