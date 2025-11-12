#include<bits/stdc++.h>
using namespace std;
int n0,n,m,max0,min0,q,num;
int a[10005][5];
int b[10005];
int c[4][10005]; 
int d[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n0;
	for(int o=1;o<=n0;o++)
	{
		num=0;
		max0=9999999;
		min0=-9999999;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[i][0]<=m)
				{
					if(b[j]==0) 
					{
						b[j]=i;
						c[i][0]++;
						q=c[i][0];
						c[i][q]=j;
					}
					else
					{
						if(a[j][i]>a[j][b[j]])
						{
							b[j]=i;
							c[i][0]++;
							q=c[i][0];
							c[i][q]=j;
						}
					}
				}
				else 
				{
					if(b[j]==0)
					{
						if(a[j][i]>min0)
						{
							b[j]=i;
							c[i][0]++;
							q=c[i][0];
							c[i][q]=j;
						}
					}
					else
					{
						if(a[j][i]>a[j][b[j]])
						{
							if(a[j][i]>min0)
							{
								b[j]=i;
								c[i][0]++;
								q=c[i][0];
								c[i][q]=j;
							}
						}
					}
				}
				max0=max(a[j][i],max0);
				min0=min(a[j][i],min0);
			}
		}
		for(int i=1;i<=n;i++)
		{
			q=b[i];
			num+=a[i][q];
		}
		cout<<num;
	}
	return 0;
}
