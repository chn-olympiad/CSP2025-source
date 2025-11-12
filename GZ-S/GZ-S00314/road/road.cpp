//GZ-S00314 遵义市播州区新蓝学校 王天垚
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;//n城市数m道路数k乡镇数 
	int x,y,z;
	//初始化 
	int u[n+1][m+1],a[k+1][n+1];
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	u[i][j]=0;
	for(int i=0;i<=k;i++)
	for(int j=0;j<=n;j++)
	a[i][j]=0;
	//输入 
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		u[x][y]=z;//u修路价格 
		u[y][x]=z;
	}
	int c[k+1];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];//修村价格 
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];//a乡镇与城市间建造道路费用
			a[j][i]=a[i][j];
		}
	}
	//寻找 
	int num[n+1][n+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			num[i][j]=0;
	int cxj[k+1],numz=0;bool ok=false;int zzda=0,le=0,iftrue=0;
	u[0][0]=0;u[1][0]=0;u[0][1]=0;u[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{	
			int num1[k+1];
			for(int ml=1;ml<=k+1;ml++)
			num1[k+1]=0;
			iftrue=0;le=0;
			for(int xc=1;xc<=k;xc++)
			{
				ok=false;
				if(u[i][j]!=0)
				{
					if(a[xc][i]!=0 && a[xc][j]!=0)
					{
						if(u[i][j]>=(a[xc][i]+a[xc][j]))
						{
							ok=true;
							num[i][j]=a[xc][i]+a[xc][j];
						}
						else
						    num[i][j]=u[i][j];
					}
					else
						num[i][j]=u[i][j];
				}
				else{
					ok=true;
					num[i][j]=a[xc][i]+a[xc][j];
				}
				//for(int l=1;l<=n;l++)
				//for(int h=1;h<=n;h++)
				numz+=num[i][j];
				if(ok){
				numz+=c[xc];
				cxj[xc]=numz+c[xc];
				num1[xc]=numz+c[xc];
				iftrue+=1;
				}else
				num1[xc]=numz;
			}
			if(iftrue>=2){
			for(int l=1;l<k;l++)
			if(num1[l]<=num1[l+1]){
			num1[l+1]=num1[l];
			le=num1[l];
			}
			else{
			num1[l]=num1[l+1];
			le=num1[l+1];}
			zzda+=le;
			}
			
		}
	}
	zzda=zzda/124;
	cout<<zzda;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
