#include<bits/stdc++.h>
using namespace std;
long long n,s,m,c[200100],a[200100][3],T;
vector<int>b[3];
bool cp(int x,int y)
{
	return c[x]>c[y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>T;
	for(;T--;)
	{
		s=0;
		cin>>n;
		for(int i=1,z;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			z=0;
			for(int j=1;j<3;j++)
			{
				if(a[i][j]>a[i][z])
				{
					z=j;
				}
			}
			s+=a[i][z];
			b[z].push_back(i);
			sort(a[i],a[i]+3);
			c[i]=a[i][2]-a[i][1];
		}
		for(int i=0;i<3;i++)
		{
			if(b[i].size()>n/2)
			{
				sort(b[i].begin(),b[i].end(),cp);
				for(int j=b[i].size();j>n/2;j--)
				{
					//cout<<b[i][j-1]<<' ';
					s-=c[b[i][j-1]];
				}
			}
			b[i].clear();
		}
		cout<<s<<"\n";
	}
}
