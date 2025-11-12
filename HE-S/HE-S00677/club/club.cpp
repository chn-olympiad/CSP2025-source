#include<bits/stdc++.h>
using namespace std;
int m,n;
int z[1000][1000],zz[1000][1000],zzz[1000][1000],a[10],b[10];
int main()
{
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	cin>>m;
	for(int k=1;k<=m;k++)
	{
		int zd=0,zj=0,zx=0,z1,z2,z3,zdd;
		int zs=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(z,0,sizeof(z));
		memset(zz,0,sizeof(zz));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>z[i][j];
			}
			if(z[i][1]>=z[i][2]&&z[i][1]>=z[i][3])
			{
				zd=z[i][1];
				z1=1;
				zz[i][1]=1;
				if(z[i][2]>=z[i][3])
				{
					zj=z[i][2];
					zx=z[i][3];
					z2=2;
					z3=3;
					zz[i][2]=2;
					zz[i][3]=3;
				}
				else
				{	
					zj=z[i][3];
					zx=z[i][2];
					z2=3;
					z3=2;
					zz[i][2]=3;
					zz[i][3]=2;
				}
			}
			if(z[i][2]>=z[i][3]&&z[i][2]>=z[i][1])
			{
				zd=z[i][2];
				z1=2;
				zz[i][1]=2;
				if(z[i][1]>=z[i][3])
				{
					zj=z[i][1];
					zx=z[i][3];
					z2=1;
					z3=3;
					zz[i][2]=1;
					zz[i][3]=3;
				}
				else
				{
					zx=z[i][1];
					zj=z[i][3];
					z2=3;
					z3=2;
					zz[i][2]=3;
					zz[i][3]=2;
				}
			}
			if(z[i][3]>=z[i][1]&&z[i][3]>=z[i][2])
			{
				zd=z[i][3];
				z1=3;
				zz[i][1]=3;
				if(z[i][2]>=z[i][1])
				{
					zj=z[i][2];
					zx=z[i][1];
					z2=2;
					z3=1;
					zz[i][2]=2;
					zz[i][3]=1;
				}
				else
				{
					zj=z[i][1];
					zx=z[i][2];	
					z2=1;
					z3=2;
					zz[i][2]=1;
					zz[i][3]=2;
				}
			}
		}
	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=n;j++)
	//		{
	//			if(z[i][zz[i+1][1]]>)
	//		}
	//	}
		for(int i=1;i<=n;i++)
		{
			if(b[zz[i][1]]<n/2)
			{
				a[zz[i][1]]+=z[i][zz[i][1]];
				b[zz[i][1]]+=1;
				continue;
			}
			if(b[zz[i][1]]<n/2)
			{
				a[zz[i][1]]+=z[i][zz[i][1]];
				b[zz[i][1]]+=1;
				continue;
			}
			if(b[zz[i][1]]<n/2)
			{
				a[zz[i][1]]+=z[i][zz[i][1]];
				b[zz[i][1]]+=1;
				continue;
			}
		}
	//	for(int i=1;i<=n;i++)
	//	{
	//		cout<<a[i]<<' ';
	//	}
	//	cout<<endl;
	//	for(int i=1;i<=n;i++)
	//	{
	//		cout<<b[i]<<' ';
	//	}
	//	cout<<endl;
	//	cout<<zs<<endl;
	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=3;j++)
	//		{
	//			cout<<z[i][j]<<' ';
	//		}
	//		cout<<endl;
	//	}
	//	cout<<' '<<endl;
	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=3;j++)
	//		{
	//			cout<<zz[i][j]<<' ';
	//		}
	//		cout<<endl;
	//	}

		cout<<a[1]+a[2]+a[3]<<endl;
	}

//		memset(z,0,sizeof(z));
//		memset(zz,0,sizeof(zz));

	return 0;
}
