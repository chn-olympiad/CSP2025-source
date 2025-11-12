#include<bits/stdc++.h>
using namespace std;
char d[1005][2005],e[1005][2005],dz[1005][2005],ez[1005][2005],dy[1005][2005],ey[1005][2005],dx[1005][2005],ex[1005][2005];
int dl[1005]={0},el[1005]={0},dzl[1005]={0},ezl[1005]={0},dyl[1005]={0},eyl[1005]={0},o=0,dxl[1005]={0},exl[1005]={0};
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,zz;
	string x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=0;j<x.size();j++)
		{
			if(x[j]==y[j])
			{
				dzl[i]++;
				dz[i][dzl[i]]=x[j];
			}else
				break;
		}
		for(int j=x.size()-1;j>=dzl[i];j--)
		{
			if(x[j]==y[j])
			{
				dyl[i]++;
				dy[i][dyl[i]]=x[j];
			}else
				break;
		}
		for(int j=dzl[i];j<=x.size()-1-dyl[i];j++)
		{
			dl[i]++;
			d[i][dl[i]]=x[j];
			dxl[i]++;
			dx[i][dxl[i]]=y[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		o=0;
		for(int j=0;j<x.size();j++)
		{
			if(x[j]==y[j])
			{
				ezl[i]++;
				ez[i][ezl[i]]=x[j];
			}else
				break;
		}
		for(int j=x.size()-1;j>=ezl[i];j--)
		{
			if(x[j]==y[j])
			{
				eyl[i]++;
				ey[i][eyl[i]]=x[j];
			}else
				break;
		}
		for(int j=ezl[i];j<=x.size()-1-eyl[i];j++)
		{
			el[i]++;
			e[i][el[i]]=x[j];
			exl[i]++;
			ex[i][exl[i]]=y[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(dxl[j]==exl[i])
			{
				int r=0;
				for(int k=1;k<=exl[i];k++)
				{
					if(d[j][k]!=e[i][k] or dx[j][k]!=ex[i][k])
					{
						r=1;
						break;
					}
				}
				if(r==0)
				{
					for(int k=ezl[i];k>=ezl[i]-dzl[j]+1;k--)
					{
						if(dz[j][k]!=ez[i][k])
						{
							r=1;
							break;
						}
					}
					if(r==0)
					{
						for(int k=eyl[i];k>=eyl[i]-dyl[j]+1;k--)
						{
							if(dy[j][k]!=ey[i][k])
							{
								r=1;
								break;
							}
						}
						if(r==0)
							o++;
					}
				}
			}
		}
		cout<<o<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
