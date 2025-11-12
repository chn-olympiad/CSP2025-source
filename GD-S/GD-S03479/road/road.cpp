#include <bits/stdc++.h>
using namespace std;
int n,m,k,k1=0;
int t1,t2,t3,t0[10001];
int a[10001],d[10001][10001],r[10001][10001],v[11][10001];
bool s[10001];
int costn[10012],res,minn;
int main()
{
	ifstream fin("road.in");
	ofstream fout("road.out");
	fin>>n>>m>>k;
	memset(d,0,sizeof(d));
	memset(t0,0,sizeof(t0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=1000000001;
		}
	}
	for(int i=1;i<=n;i++)
	{
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		fin>>t1>>t2>>t3;
		d[t1][t2]=d[t2][t1]=t3;
		r[t1][++t0[t1]]=t2;r[t2][++t0[t2]]=t1;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			fin>>t1;//v[i][0]=construct itself
			v[i][j]=t1;
		}
	}
	for(int I=0;I<=0;I++)
	{
		memset(s,0,sizeof(s));
		for(int i=2;i<=n;i++)
		{
			costn[i]=d[i][1];
		}
		for(int i=1;i<=k1;i++)
		{
			costn[i+n]=v[i][1];
		}
		costn[1]=0;s[1]=1;
		for(int i=1;i<n;i++)
		{
			t1=0;minn=1000000001;
			for(int j=2;j<=n;j++)
			{
				if(costn[j]<=minn&&(!s[j]))
				{
					t1=j;
					minn=costn[j];
				}
			}
			for(int j=1;j<=k1;j++)
			{
				if(costn[j+n]<=minn&&(!s[j+n]))
				{
					t1=j+n;
					minn=costn[j+n];
				}
			}
			s[t1]=1;
			res+=minn;
			for(int j=1;j<=t0[t1];j++)
			{
				costn[r[t1][j]]=min(d[r[t1][j]][t1],costn[r[t1][j]]);
			}
			for(int j=1;j<=k1;j++)
			{
				costn[n+j]=min(v[j][t1],costn[n+j]);
			}
		}
		fout<<res<<endl;
	}
	return 0;
}
