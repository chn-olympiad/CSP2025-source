#include<bits/stdc++.h>
using namespace std;
bool judge(int x,int y)
{
	return x>y;
}
long long maxx[100086]={},a1[200000]={},a2[1000054]={},a3[51021021]={};
long long sum1=0;
	long long n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		maxx[100086]={};a1[200000]={};a2[1000054]={};a3[51021021]={};
		sum1=0;
		cin>>n;
		bool c=0,d=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
			maxx[j]=max(a1[j],max(a2[j],a3[j]));
			if(a2[j]!=0)
			{
				c=1;
			}
			if(a2[j]!=0)
			{
				d=1;
			}
		}
		if(n==2)
		{
			int sum=0;
			sum=max(a1[1]+a2[2],max(a1[1]+a3[2],max(a2[1]+a1[2],max(a2[1]+a3[2],max(a3[1]+a1[2],a3[1]+a2[2])))));
			cout<<sum<<endl;
			continue;
		}
		if(n==4)
		{
			int x[10000000]={}; 
			x[1]=a1[1]+a1[2]+a2[3]+a2[4];
			x[2]=a1[1]+a1[2]+a2[3]+a3[4];
			x[3]=a1[1]+a2[2]+a2[3]+a3[4];
			x[4]=a1[1]+a2[2]+a3[3]+a2[4];
			x[5]=a1[1]+a2[2]+a3[3]+a3[4];
			x[6]=a1[1]+a3[2]+a2[3]+a3[4];
			x[7]=a1[1]+a3[2]+a2[3]+a2[4];
			x[8]=a2[1]+a1[2]+a1[3]+a2[4];
			x[9]=a2[1]+a1[2]+a1[3]+a3[4];
			x[10]=a2[1]+a1[2]+a2[3]+a3[4];
			x[11]=a2[1]+a1[2]+a3[3]+a3[4];
			x[12]=a2[1]+a2[2]+a3[3]+a3[4];
			x[13]=a2[1]+a2[2]+a3[3]+a1[4];
			x[14]=a2[1]+a3[2]+a1[3]+a2[4];
			x[15]=a2[1]+a3[2]+a2[3]+a1[4];
			x[16]=a2[1]+a3[2]+a3[3]+a2[4];
			x[17]=a2[1]+a3[2]+a3[3]+a1[4];
			x[18]=a3[1]+a1[2]+a2[3]+a2[4];
			x[19]=a3[1]+a1[2]+a2[3]+a3[4];
			x[20]=a3[1]+a1[2]+a3[3]+a2[4];
			x[21]=a3[1]+a1[2]+a1[3]+a3[4];
			x[22]=a3[1]+a1[2]+a1[3]+a2[4];
			x[23]=a3[1]+a1[2]+a2[3]+a2[4];
			x[24]=a3[1]+a1[2]+a3[3]+a3[4];
			x[25]=a3[1]+a2[2]+a2[3]+a3[4];
			x[26]=a3[1]+a2[2]+a1[3]+a2[4];
			x[27]=a3[1]+a2[2]+a3[3]+a2[4];
			x[28]=a3[1]+a2[2]+a1[3]+a1[4];
			x[29]=a3[1]+a2[2]+a1[3]+a3[4];
			x[30]=a3[1]+a2[2]+a1[3]+a3[4];
			x[31]=a3[1]+a3[2]+a1[3]+a1[4];
			x[32]=a3[1]+a3[2]+a2[3]+a2[4];
			x[33]=a3[1]+a3[2]+a2[3]+a1[4];
			x[34]=a3[1]+a3[2]+a1[3]+a2[4];
			int sum=-1;
			for(int j=1;j<=34;j++)
			{
				sum=max(sum,x[i]);
			}
			cout<<sum<<endl;
			continue;
		}
		sort(maxx+1,maxx+1+n,judge);
		if(d==0)
		{
			if(c==0)
			{
				for(int j=1;j<=n/2;j++)
				{
					sum1+=maxx[j];
				}
				cout<<sum1<<endl;
				continue;
			}
			else
			{
				int o1=n/2;
				int o2=n/2;
				for(int j=1;j<=n;j++)
				{
					sum1+=maxx[j];
				}
				cout<<sum1<<endl;
				continue;		
			}
		}
	}
	return 0;
}