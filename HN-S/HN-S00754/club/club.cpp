#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],b[4],c[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		b[1]=0;b[2]=0;b[3]=0;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=3;l++)
			{
				scanf("%d",&a[j][l]);
			}
			c[j]=max(a[j][1],max(a[j][2],a[j][3]));
		}
		for(int j=1;j<n;j++)
		{
			for(int k=1;k<n;k++)
			{
				if(c[k]>c[k+1])
				{
					swap(a[k][1],a[k+1][1]);
					swap(a[k][2],a[k+1][2]);
					swap(a[k][3],a[k+1][3]);
					swap(c[k],c[k+1]);
				}
			}
		}
		for(int k=n-1;k>=1;k--)
		{
			for(int j=1;j<=3;j++)
			{
				if((b[1]==n/2&&j==1)||(b[1]==n/2-1&&j==1))
				{
					if(a[k+1][2]>a[k+1][3])
					{
						a[k][j]+=a[k+1][2];
						b[2]++;
					}
					else if(a[k+1][2]<a[k+1][3])
					{
						a[k][j]+=a[k+1][3];
						b[3]++;
					}
					else
					{
						a[k][j]+=a[k+1][2];
					}
				}
				else if((b[2]==n/2&&j==2)||(b[2]==n/2-1&&j==2))
				{
					if(a[k+1][1]>a[k+1][3])
					{
						a[k][j]+=a[k+1][1];
						b[1]++;
					}
					else if(a[k+1][1]<a[k+1][3])
					{
						a[k][j]+=a[k+1][3];
						b[3]++;
					}
					else
					{
						a[k][j]+=a[k+1][1];
					}
				}
				else if((b[3]==n/2&&j==3)||(b[3]==n/2-1&&j==3))
				{
					if(a[k+1][2]>a[k+1][1])
					{
						a[k][j]+=a[k+1][2];
						b[2]++;
					}
					else if(a[k+1][2]<a[k+1][1])
					{
						a[k][j]+=a[k+1][1];
						b[1]++;
					}
					else
					{
						a[k][j]+=a[k+1][2];
					}
				}
				else
				{
					if(a[k+1][2]>a[k+1][1]&&a[k+1][2]>a[k+1][3])
					{
						a[k][j]+=a[k+1][2];
						b[2]++;
					}
					else if(a[k+1][3]>a[k+1][1]&&a[k+1][3]>a[k+1][2])
					{
						a[k][j]+=a[k+1][3];
						b[3]++;
					}
					else if(a[k+1][1]>a[k+1][2]&&a[k+1][1]>a[k+1][3])
					{
						a[k][j]+=a[k+1][1];
						b[1]++;
					}
					else
					{
						a[k][j]+=a[k+1][1];
					}
				}
			}
		}
		cout<<max(a[1][1],max(a[1][2],a[1][3]))<<endl;
	}
	return 0;
}
