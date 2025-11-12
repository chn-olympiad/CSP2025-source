#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	//cout<<666<<" "<<667;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		//cout<<n;
		//p=n/2;
		int a[n][4];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				//a[i][j].id=j;
			}
		/*for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				cout<<a[i][j]<<endl;
				//a[i][j].id=j;
			}*/
		int maxx=0;
		for(int k=1;k<=3;k++)
		{
			//int num=0;
			if(n==2)
			{
				for(int i=1;i<=3;i++)
				{
					if(k==i)    continue;
					int t=a[1][k]+a[2][i];
					maxx=max(t,maxx);
				}
			}
			if(n==4)
			{
				for(int i=1;i<=3;i++)
					for(int j=1;j<=3;j++)
						for(int t=1;t<=3;t++)
							if(!(k==i && j==t || k==j && i==t || k==t && i==j))
							{
								int x=a[1][k]+a[2][i]+a[3][j]+a[4][t];
								maxx=max(x,maxx);
							}
			}
		}
		cout<<maxx;
	}
	return 0;
}
