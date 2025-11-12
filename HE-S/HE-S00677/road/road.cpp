#include<bits/stdc++.h>
using namespace std;
int m,n,zzs;
int z[1000];
int main()
{
	int a=0,b=0,c=0,zd=0,zj=0,zx=0;
	cin>>m;
	for(int k=1;k<=m;k++)
	{	
		int zzs=0,zs=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int sx=n/2,zs=0,js=0,jss=0;
			zd=0,zj=0,zx=0;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				zd=a;
				if(b>c)
				{
					zj=b;
					zx=c;
				}
				else
				{
					zx=b;
					zj=c;
				}
			}
			if(b>c&&b>a)
			{
				zd=b;
				if(a>c)
				{
					zj=a;
					zx=c;
				}
				else
				{
					zx=a;
					zj=c;
				}
			}
			if(c>a&&c>b)
			{
				zd=c;
				if(b>a)
				{
					zj=b;
					zx=a;
				}
				else
				{
					zx=b;
					zj=a;
				}
			}
			if(a==b==c)
			{
				zd=a;
				zj=b;
				zx=c;
			}
			if(js<sx)
			{
				zs+=zd;
				js+=1;
			}
			else if(jss<sx)
			{
				zs+=zj;
				jss+=1;
			}
			else
			{
				zs+=zx;
			}
			zzs+=zs;
		}
		cout<<zzs<<endl;
	}
	
	
	return 0;
}
