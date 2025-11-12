//GZ-S00160 遵义市第一初级中学 张桢宇
#include<bits/stdc++.h>
using namespace std;

int t,n[5],a[5][100000][3],b[5][100000][3],h[5],s[5][3],d[5],ds[5],r[5][100000],y;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n[i]);
		for(int j=0;j<n[i];j++)
		{
			scanf("%d %d %d",&a[i][j][1],&a[i][j][2],&a[i][j][3]);
			if(a[i][j][1]>a[i][j][2])
				if(a[i][j][1]>a[i][j][3])
				{
					b[i][j][0]=a[i][j][1];
					s[i][1]++;
				}
				else
				{
					b[i][j][0]=a[i][j][3];
					s[i][3]++;
				}
			else
				if(a[i][j][2]>a[i][j][3])
				{
					b[i][j][0]=a[i][j][2];
					s[i][2]++;
				}
				else
				{
					b[i][j][0]=a[i][j][3];
					s[i][3]++;
				}
			h[i]+=b[i][j][0];
			b[i][j][1]=b[i][j][0]-a[i][j][1];
			b[i][j][2]=b[i][j][0]-a[i][j][2];
			b[i][j][3]=b[i][j][0]-a[i][j][3];
		}
	}
	for(int i=0;i<t;i++)
	{
		if(s[i][1]>s[i][2])
			if(s[i][1]>s[i][3])
			{
				d[i]=1;
				ds[i]=s[i][1];
			}
			else
			{
				d[i]=3;
				ds[i]=s[i][3];
			}
		else
			if(s[i][2]>s[i][3])
			{
				d[i]=2;
				ds[i]=s[i][2];
			}
			else
			{
				d[i]=3;
				ds[i]=s[i][3];
			}
		if(ds[i]<=n[i]/2) cout<<h[i]<<endl;
		else
		{
			y=0;
			for(int j=0;j<n[i];j++)
				if(b[i][j][d[i]]==min(b[i][j][1],min(b[i][j][2],b[i][j][3])))
					if(d[i]==1)
					{
						r[i][y]=min(b[i][j][2],b[i][j][3]);
						y++;
					}
					else if(d[i]==2)
						{
							r[i][y]=min(b[i][j][1],b[i][j][3]);
							y++;
						}
						else
						{
							r[i][y]=min(b[i][j][2],b[i][j][1]);
							y++;
						}
			sort(r[i],r[i]+y-1);
			for(int j=0;j<ds[i]-n[i]/2;j++)
				h[i]-=r[i][j];
			cout<<h[i]<<endl;
		}
	}
    return 0;
	fclose(stdin);
	fclose(stdout);
}
