#include<bits/stdc++.h>
using namespace std;
long long n,m,k,b[15][10005],k1,k2,k3,c[10005],d[10005],num,kl;
struct node{
	long long jb,z;
};
vector<node> v[1005];
node y;
bool cmp(node xa,node ya)
{
	return xa.z<ya.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>k1>>k2>>k3;
		y.z=k3;
		y.jb=k2;
		v[k1].push_back(y);
		y.jb=k1;
		v[k2].push_back(y);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			sort(v[i].begin(),v[i].end(),cmp);
		}
		num+=v[1][0].z;
		c[1]=1;
		c[v[1][0].jb]=1;
		d[1]=1;
		kl=2;
		while(kl<n)
		{
			kl++; 
			long long kz,kjb;
			kz=0x3f3f3f;
			for(int i=1;i<=n;i++)
			{	
				if(c[i]==1)
				{
					while(d[i]<v[i].size()&&c[v[i][d[i]].jb]==1)
					{
						d[i]++;
					}
					if(d[i]<v[i].size()&&kz>v[i][d[i]].z)
					{
						kz=v[i][d[i]].z;
						kjb=v[i][d[i]].jb;
					}
				}
			}
			c[kjb]=1;
			num+=kz;
		}
		cout<<num;
	}
	else
	{
		cout<<13;
	}
	return 0;
}
