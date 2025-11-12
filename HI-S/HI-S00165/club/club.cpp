#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
long long c[4]={0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,m;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>m;
		long long a[m+1][4]={0},b[m+1]={0},d[m+1]={0};
		for(long long i=1;i<=m;i++)
		{
			for(long long j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>=d[i])
				{
					d[i]=a[i][j];
					b[i]=j;
					//cout<<1<<endl;
				}
			}
			c[b[i]]++;
		}
		long long x=max(max(c[1],c[2]),c[3]),y;
		//cout<<x<<endl;
		if(x==c[1])
		y=1;
		else if(x==c[2])
		y=2;
		else
		y=3;//x是最大人数社团的人数，y是社团编号 
		int s=0,q;
		if(x<=m/2)
		{
			//cout<<1<<endl;
			for(long long i=1;i<=m;i++)
			{
				s+=a[i][b[i]];
				//cout<<a[i][b[i]]<<endl;
			}
		}
		else
		{
			//cout<<2<<endl;
			for(long long i=1;i<m;i++)
			{
				for(long long j=1;j<m;j++)
				{
					if(a[j][y]<a[j+1][y])
					{
						swap(a[j][y],a[j+1][y]);
						swap(a[j][y+1],a[j+1][y+1]);
						swap(a[j][y-1],a[j+1][y-1]);
						swap(a[j][y-2],a[j+1][y-2]);
						swap(a[j][y+2],a[j+1][y+2]);
					}
				} 
			}
			for(long long i=1;i<m;i++)
			{
				if(i<=m/2)
				{
					s+=a[i][y];
					//cout<<a[i][y]<<endl;
				}
				else if(y==1)
				s+=max(a[i][2],a[i][3]);
				else if(y==2)
				s+=max(a[i][1],a[i][3]);
				else
				s+=max(a[i][1],a[i][2]);
			}
			if(y==1)
			s+=max(a[m][2],a[m][3]);
			else if(y==2)
			s+=max(a[m][1],a[m][3]);
			else
			s+=max(a[m][2],a[m][1]);
		}
		cout<<s<<endl;
	}
	return 0;
}

