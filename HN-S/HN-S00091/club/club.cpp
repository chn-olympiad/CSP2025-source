#include<bits/stdc++.h>
using namespace std;
int da[100002][3][2];
int a,b,c;
bool a1[100002],b1[100002],c1[100002];
int f[32][32][32][32];
int maxx,pi;
bool we;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t!=0)
	{
		t--;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&da[i][0][0],&da[i][1][0],&da[i][2][0]);
			if(da[i][2][0])
			we=1;
		}
		if(n<=30&&we)
		{
			int maxx=-1;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2&&j<=i;j++)
				{
					for(int k=0;k<=n/2&&k<=i;k++)
					{
						int h=i-j-k;
						if(h<=n/2&&h<=i&&h>=0)
						{
							if(h>=1)
							f[i][j][k][h]=max(f[i-1][j][k][h-1]+da[i][2][0],f[i][j][k][h]);
							if(j>=1)
							f[i][j][k][h]=max(f[i-1][j-1][k][h]+da[i][0][0],f[i][j][k][h]);
							if(k>=1)
							f[i][j][k][h]=max(f[i-1][j][k-1][h]+da[i][1][0],f[i][j][k][h]);
							maxx=max(maxx,f[i][j][k][h]);
							//cout<<i<<" "<<j<<" "<<k<<" "<<h<<endl;
						}
					}
				}
			}
			cout<<maxx<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2&&j<=i;j++)
				{
					for(int k=0;k<=n/2&&k<=i;k++)
					{
						int h=i-j-k;
						f[i][j][k][h]=0;
					}
				}
			}
			continue;
		}
		for(int i=1;i<=n/2;i++)
		{
			a=da[i][0][0]+a;
			da[i][0][1]=max(da[i][1][0],da[i][2][0]);
			b=da[i][1][0]+b;
			da[i][1][1]=max(da[i][3][0],da[i][2][0]);
			c=da[i][2][0]+c;
			da[i][2][1]=max(da[i][1][0],da[i][3][0]);
		}
		for(int i=n/2+1;i<=n;i++)
		{
			da[i][0][1]=max(da[i][1][0],da[i][2][0]);
			da[i][1][1]=max(da[i][3][0],da[i][2][0]);
			da[i][2][1]=max(da[i][1][0],da[i][3][0]);
		}
		for(int i=n/2+1;i<=n;i++)
		{
			maxx=da[i][0][1];
			pi=0;
			for(int j=1;j<=n/2;j++)
			{
				if(!a1[j]&&maxx<da[j][0][1]+da[i][0][0]-da[j][0][0])
				{
					pi=j;
					maxx=da[j][0][1]+da[i][0][0]-da[j][0][0];
				}
			}
			a1[pi]=1;
			a=a+maxx;
		//	cout<<pi<<endl;
			pi=0;
			maxx=da[i][1][1];
			for(int j=1;j<=n/2;j++)
			{
				if(!b1[j]&&maxx<da[j][1][1]+da[i][1][0]-da[j][1][0])
				{
					pi=j;
					maxx=da[j][1][1]+da[i][1][0]-da[j][1][0];
				}
			}
			b1[pi]=1;
			b=b+maxx;
		//	cout<<pi<<endl;
			pi=0;
			maxx=da[i][2][1];
			for(int j=1;j<=n/2;j++)
			{
				if(!c1[j]&&maxx<da[j][2][1]+da[i][2][0]-da[j][2][0])
				{
					pi=j;
					maxx=da[j][2][1]+da[i][2][0]-da[j][2][0];
				}
			}
			c1[pi]=1;
			c=c+maxx;
		//	cout<<pi<<endl;
			pi=1;
			//cout<<a<<" "<<b<<" "<<c<<endl;
		}
		cout<<max(max(a,b),c)<<endl;
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(c1,0,sizeof(c1));
		a=0;
		b=0;
		c=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
