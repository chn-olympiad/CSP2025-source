#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long  T,n,a[300005],c[300005],b[300005],num=0,k[10][10],qjh[300005],ba[3],bb[3],bc[3],m1,m2,m3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int u=1;u<=T;u++)
	{
		cin>>n;
		for(int i=1;i<=3*n;i++)
		{
			cin>>a[i];
		}
		k[1][1]=1;k[1][2]=0;k[1][3]=0;
		k[2][1]=0;k[2][2]=1;k[2][3]=0;
		k[3][1]=0;k[3][2]=0;k[3][3]=0;
		qjh[1]=a[1];qjh[2]=a[2];qjh[3]=a[3];
		ba[1]=1;bb[1]=2;bc[1]=3;
		int temp1=0,temp2=0;
		int maxx=-99999,minn=99999;
		for(int i=4;i<=n*3;i+=3)
		{
			for(int j=1;j<=3;j++)
			{
				if(qjh[j+i-4]>maxx)
				{
					maxx=qjh[j+i-4];
					temp1=(j+i-4)%3;
				}
				if(qjh[j+i-4]>maxx)
				{
					minn=qjh[j+i-4];
					temp2=(j+i-4)%3;
				}
			}
			if(k[temp1][i%3]+1<=n/2)
			{
				k[temp1][i%3]++;
				m1=qjh[1]+a[i];
			}
			else
			{
				if(a[i]+a[ba[1]]>qjh[1]&&a[i]+a[ba[1]]>a[i]+a[ba[2]])
				{
					ba[2]=i;
					m1=a[i]+a[ba[1]];
				}
				else if(a[i]+a[ba[2]]>qjh[1]&&a[i]+a[ba[2]]>a[i]+a[ba[1]])
				{
					ba[1]=i;
					m1=a[i]+a[ba[2]];
				}
				else
				{
					if(temp2!=2)
					{
						m1=qjh[1]+a[i%3+1];
						k[1][2]++;
					}
					else
					{
						m2=qjh[1]+a[i%3+2];
						k[1][3]++;
					}
					 
				}
			}
			if(k[temp1][i%3+1]+1<=n/2)
			{
				k[temp1][i%3+2]++;
				qjh[2]+=a[i+1];
			}
			else
			{
				if(a[i+1]+a[bb[1]]>qjh[2]&&a[i+1]+a[bb[1]]>a[i+1]+a[bb[2]])
				{
					bb[2]=i;
					m2=a[i+1]+a[bb[1]];
				}
				else if(a[i+1]+a[bb[2]]>qjh[2]&&a[i+1]+a[bb[2]]>a[i+1]+a[bb[1]])
				{
					bb[1]=i;
					m2=a[i+1]+a[bb[2]];
				}
				else
				{
					if(temp2!=1)
					{
						m2=qjh[2]+a[i%3+2];
						k[2][3]++;
					}
					else
					{
						m2=qjh[2]+qjh[i%3];
						k[2][1]++;
					}
					 
				}
			}
			if(k[temp1][i%3+2]+1<=n/2)
			{
				k[temp1][i%3+2]++;
				qjh[3]+=a[i+2];
			}
			else
			{
				if(a[i+2]+a[bc[1]]>qjh[3]&&a[i+2]+a[bc[1]]>a[i+2]+a[bc[2]])
				{
					bc[2]=i;
					m3=a[i+2]+a[bc[1]];
				}
				else if(a[i+2]+a[bc[2]]>qjh[3]&&a[i+2]+a[bb[2]]>a[i+2]+a[bc[1]])
				{
					bb[1]=i;
					m3=a[i+2]+a[bc[2]];
				}
				else
				{
					if(temp2!=2)
					{
						m3=qjh[3]+a[i%3];
						k[3][1]++;
					}
					else
					{
						m3=qjh[3]+a[i%3+1];
						k[3][2]++;
					}
					 
				}
			}
			qjh[1]=m1;
			qjh[2]=m2;qjh[3]=m3;
		}
		long long h=-99999; 
		for(int i=1;i<=3;i++)
		{
			if(qjh[i]>h)
			{
				h=qjh[i];
				}	
		}
		cout<<h<<endl;
	}
	
	return 0;
}
