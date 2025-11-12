#include <bits/stdc++.h>
using namespace std;
string a[10000][4];
string b[10000][3];
long long n,m,l,x,s,al[10000][3],bl[10000][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	{
		getline(cin,a[i][0]);
		l=a[i][0].size();
		for(int j=0;j<l;j++)
		{
			if(a[i][0][j]==' ') x=j;
			else if(x==0) a[i][1][j]=a[i][0][j];
			else a[i][2][j-1-x]=a[i][0][j];
		}
		x=0;
		al[i][1]=a[i][1].size();
		al[i][2]=a[i][2].size();
	}
	for(int i=0;i<m;i++)
	{
		getline(cin,b[i][0]);
		l=b[i][0].size();
		for(int j=0;j<l;j++)
		{
			if(b[i][0][j]==' ') x=j;
			else if(x==0) b[i][1][j]=b[i][0][j];
			else b[i][2][j-1-x]=b[i][0][j];
		}
		x=0;
		bl[i][1]=b[i][1].size();
		bl[i][2]=b[i][2].size();
	}
	for(int i=0;i<m;i++)
	{
		for(long long j=0;j<n;j++)
		{
			for(long long k=0;k<bl[i][1]-al[j][1];k++)
			{
				x=0;
				for(long long y=0;y<al[j][1];y++)
				{
					if(b[i][1][k+y]!=a[j][1][y]) x=1;
				}
				if(x==0)
				{
					b[i][3]=b[i][2];
					for(long long y=0;y<al[j][1];y++)
					{
						b[i][3][k+y]=a[j][2][y];
					}
					for(long long y=0;y<max(bl[i][2],bl[i][1]);y++)
					{
						if(b[i][1][y]!=b[i][2][y]) x=1;
					}
					if(x==0) s++;
				}
			}
		}
		cout<<s<<endl;
		s=0;
	}
	return 0;
}
