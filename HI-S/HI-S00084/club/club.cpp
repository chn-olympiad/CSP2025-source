#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],maxx[100005],maxxtw[100005],maxxth[10005],t[5],x,y,z,sum,tt[100005],summ;
bool cmp(int q,int p)
{
	return q>p;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		summ=0;
		sum=0;
		if(n==2)
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
				t[1]=a[i][1];
				t[2]=a[i][2];
				t[3]=a[i][3];
				sort(t+1,t+4,cmp);
				maxx[i]=t[1];
				maxxtw[i]=t[2];
				maxxth[i]=t[3];
//				cout<<maxx[i]<<' '<<maxxtw[i]<<' '<<maxxth[i]<<endl;
			}
			if(maxx[1]==a[1][1]&&maxx[2]==a[2][1])
			{
				if(a[1][1]-maxxtw[1]>a[2][1]-maxxtw[2])
				{
					sum+=maxxtw[2]+a[1][1];
					cout<<sum<<endl;
				}
				else
				{
					sum+=maxxtw[1]+a[2][1];
					cout<<sum<<endl;
				}
			}
			else if(maxx[1]==a[1][2]&&maxx[2]==a[2][2])
			{
				if(a[1][2]-maxxtw[1]>a[2][2]-maxxtw[2])
				{
					sum+=maxxtw[2]+a[1][2];
					cout<<sum<<endl;
					
				}
				else
				{
					sum+=maxxtw[1]+a[2][2];
					cout<<sum<<endl;
					
				}
			}
			else if(maxx[1]==a[1][3]&&maxx[2]==a[2][3])
			{
				if(a[1][3]-maxxtw[1]>a[2][3]-maxxtw[2])
				{
					sum+=maxxtw[2]+a[1][3];
					cout<<sum<<endl;
					
				}
				else
				{
					sum+=maxxtw[1]+a[2][3];
					cout<<sum<<endl;
					
				}
			}
			else
			{
				sum+=maxx[1]+maxx[2];
				cout<<sum<<endl;
			}
		}
		else
		{
			int maxxx=-1;
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
				tt[i]=a[i][1];
			}
			sort(tt+1,tt+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				summ+=tt[i];
			}
			cout<<summ;
		}
	}
	return 0;
}
