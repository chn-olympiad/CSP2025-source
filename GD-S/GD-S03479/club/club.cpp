#include <bits/stdc++.h>
using namespace std;
int n,t,temp;
int a[100001][3],amax[100001][2][2],c[3],res;
struct B{
	int k1;
	int k2;
}b[100001];
bool judgef(B &a,B &b)
{
	if(a.k1>b.k1)
	{
		return 0;
	}
	return 1;
}
int main()
{
	ifstream fin("club.in");
	ofstream fout("club.out");
	fin>>t;
	for(int I=0;I<t;I++)
	{
		memset(a,0,sizeof(a));
		fin>>n;
		for(int i=0;i<n;i++)
		{
			fin>>a[i][0];
			amax[i][0][0]=a[i][0];amax[i][0][1]=0;
			for(int j=1;j<3;j++)
			{
				fin>>a[i][j];
				if(a[i][j]>=amax[i][0][0])
				{
					amax[i][1][0]=amax[i][0][0];amax[i][1][1]=amax[i][0][1];
					amax[i][0][0]=a[i][j];amax[i][0][1]=j;
				}
				else
				{
					if(a[i][j]>=amax[i][1][0])
					{
						amax[i][1][0]=a[i][j];amax[i][1][1]=j;
					}
				}
			}
			b[i].k1=amax[i][0][0]-amax[i][1][0];
			b[i].k2=i;
		}
		sort(b,b+n,judgef);
		memset(c,0,sizeof(c));
		res=0;
		for(int i=0;i<n;i++)
		{
			c[amax[b[i].k2][0][1]]++;
			res+=amax[b[i].k2][0][0];
		}
		for(int j=0;j<3;j++)
		{
			if(c[j]>n/2)
			{
				for(int i=0;c[j]>n/2;i++)
				{
					if(amax[b[i].k2][0][1]==j)
					{
						c[j]--;
						res-=b[i].k1;
					}
				}
				break;
			}
		}
		fout<<res<<endl;
	}
	return 0;
}
