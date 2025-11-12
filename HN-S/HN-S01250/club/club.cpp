#include<bits/stdc++.h>
using namespace std;
int t,n,s;
int v[100005][5],f[100000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(t;t>0;t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>v[i][j];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int k=3;k>=1;k--)
			{
				f[i]=max(f[i],f[i-1]+v[i][k]);
			}
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
