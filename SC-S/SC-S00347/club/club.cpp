#include<bits/stdc++.h>
int s[10],c[10][10],a[10][3],b[10][10];
using namespace std;
int main()
{
	freopen("club.in.txt","r",stdin);
	freopen("club.out,txt","w",stdout);
	int t,n,m,j;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int w=0;w<n
			for(int z=0;z<3;z++)
			{
				scanf("%;w++)
		{d",&a[j][z]);
				c[i][j]=max(a[j][z],c[i][j]);
			}
			for(int y=0;y<3;y++)
				if(a[j][y]==c[i][j])
				{
					b[i][y]++;
					j=y;
					break;
				} 
			m=c[i][j];
			if(b[i][j]<=n/2) s[i]+=c[i][j];
			else 
			{
				c[i][j]=0;
				for(int x=0;x<3;x++) if(a[j][x]!=m) c[i][j]=max(a[j][x],c[i][j]);
				s[i]+=c[i][j];
			}
		}
	}
	for(int i=0;i<3;i++) cout<<s[i]<<endl;
	return 0;
} 