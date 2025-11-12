#include <bits/stdc++.h>
using namespace std;
int t,n,maxn=0,minn=0x3f3f3f3f,mid=0;
int maxx,maxxx,midx,midxx,minx,minxx,maxa,maxaa,mina,minaa,mida,midaa;
long long num=0;
int a[5][5]={0},b[100005]={0},as,sa;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n>=2)
		{
			int x=n/2,num=0;
			for(int j=1;j<=n;j++)
			{
				cin>>b[j]>>as>>sa;
			}
			sort(b+1,b+1+n);
			for(int j=x+1;j<=n;j++)
			{
				cout<<b[j]<<" ";
				num+=b[j];
			}
			cout<<num<<endl;
			break;
		}
		else
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[1][j];
				maxn=max(maxn,a[1][j]);
				maxx=1;
				maxxx=j;
				minn=min(minn,a[1][j]);
				minx=1;
				minxx=j;
			}
			for(int j=1;j<=3;j++)
			{
				if(a[1][j]!=maxn && a[1][j]!=minn)
				{
					mid=a[1][j];
					midx=1;
					midxx=j;
				}
			}
			maxn=0;
			minn=0x3f3f3f3f;
			for(int j=1;j<=3;j++)
			{
				cin>>a[2][j];
				maxn=max(maxn,a[2][j]);
				maxa=2;
				maxaa=j;
				minn=min(minn,a[2][j]);
				mina=2;
				minaa=j;
			}
			for(int j=1;j<=3;j++)
			{
				if(a[2][j]!=maxn && a[2][j]!=minn)
				{
					mid=a[2][j];
					mida=2;
					midaa=j;
				}
				if(a[2][j]!=maxn)
				{
					mid=a[2][j];
					mida=2;
					midaa=j;
				}
			}
			if(maxxx==maxaa)
			{
				if(a[maxx][maxxx]-a[midx][midxx]>a[maxa][maxaa]-a[mida][midaa])
				{
					cout<<a[maxx][maxxx]+a[mida][midaa]<<endl;
					for(int i=1;i<=2;i++)
					{
						for(int j=1;j<=3;j++)
						{
							a[i][j]=0;
						}
					}
					continue;
				}
				else
				{
					cout<<a[midx][midxx]+a[maxa][maxaa]<<endl;
					for(int i=1;i<=2;i++)
					{
						for(int j=1;j<=3;j++)
						{
							a[i][j]=0;
						}
					}
					continue;
				}
			}
			else
			{
				cout<<a[maxx][maxxx]+a[maxa][maxaa]<<endl;
				for(int i=1;i<=2;i++)
				{
					for(int j=1;j<=3;j++)
					{
						a[i][j]=0;
					}
				}
				continue;
			}
		}
	}
	return 0;
}
