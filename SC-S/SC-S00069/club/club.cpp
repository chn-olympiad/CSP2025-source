#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
void k()
{
	int n,b[3],fdsa;
	cin>>n;
	int f[N][3];
	fdsa=n/2;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
		{
			cin>>f[j][i];
		}
	}
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(b[i]>fdsa)
			{
				f[i][j]=max(f[i][j],f[i][j-1]);
			}
			else
			{
				if(f[i][j]=max(f[1][j],max(f[2][j],f[0][j])))
				{
					f[i][j]+=f[i][j-1];
					++b[i];
				}
				else
				{
					f[i][j]=max(f[i-1][j],f[i][j]);
				}
			}
		}
	}
	cout<<f[n-1][2]+f[n-1][1]+f[n-1][0]-1<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		k();
	}
	return 0;
}
