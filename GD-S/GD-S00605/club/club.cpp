#include <iostream>
#include <cstdio>
using namespace std;
long long fre[200005][3];
long long frenum[200005][3];
/*
1
6
4 2 1
3 2 4
5 3 4
5 3 1
6 5 5
5 5 5
*/
//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		long long n,anum=0,bnum=0,cnum=0,sum=0;
		cin>>n;
		for(long long j=1;j<=n;j++)
		{
			long long a,b,c;
			cin>>a>>b>>c;
			fre[j][0]=a;
			fre[j][1]=b;
			fre[j][2]=c;
			long long x=max(a,b); 
			sum=sum+max(x,c);
			if(max(x,c)==a)
			{
				anum++;
				frenum[j][0]=0;
				frenum[j][1]=a-b;
				frenum[j][2]=a-c;
			}
			else if(max(x,c)==b)
			{
				bnum++;
				frenum[j][0]=b-a;
				frenum[j][1]=0;
				frenum[j][2]=b-c;
			}
			else
			{
				cnum++;
				frenum[j][0]=c-a;
				frenum[j][1]=c-b;
				frenum[j][2]=0;
			}
			//cout<<frenum[j][0]<<" "<<frenum[j][1]<<" "<<frenum[j][2]<<" "<<endl;
		}
		if(anum>n/2)
		{
			//cout<<anum;
			long long x=anum-n/2,tong[20005]={};
			for(long long j=1;j<=x;j++)
			{
				long long minn=200005;
				long long w,wx;
				for(long long k=1;k<=n;k++)
				{
					if(tong[k]==0&&frenum[k][0]==0)
					{
						if(minn>min(frenum[k][1],frenum[k][2]))
						{
							minn=min(frenum[k][1],frenum[k][2]);
							w=k;
							if(min(frenum[k][1],frenum[k][2])==frenum[k][1])
							{
								wx=1;
							}
							else
							{
								wx=2;
							}
						}
					}
				}
				tong[w]++;
				anum--;
				//cout<<1<<w;
				if(wx==1)
				{
					
					sum=sum-frenum[w][1];
					frenum[w][0]=20005;
					frenum[w][1]=0;
					frenum[w][2]=fre[w][1]-fre[w][2];
					bnum++;
				}
				else
				{
					sum=sum-frenum[w][2];
					frenum[w][0]=20005;
					frenum[w][2]=0;
					frenum[w][1]=fre[w][2]-fre[w][1];
					cnum++;
				}
			}
			
		}
		if(bnum>n/2)
		{
			//cout<<anum;
			long long x=bnum-n/2,tong[20005]={};
			for(long long j=1;j<=x;j++)
			{
				long long minn=200005;
				long long w,wx;
				for(long long k=1;k<=n;k++)
				{
					if(tong[k]==0&&frenum[k][1]==0)
					{
						if(minn>min(frenum[k][0],frenum[k][2]))
						{
							minn=min(frenum[k][0],frenum[k][2]);
							w=k;
							if(min(frenum[k][0],frenum[k][2])==frenum[k][0]&&anum<n/2)
							{
								wx=0;
							}
							else
							{
								wx=2;
							}
						}
					}
				}
				tong[w]++;
				bnum--;
				//cout<<1<<w;
				if(wx==0)
				{
					
					sum=sum-frenum[w][0];
					frenum[w][1]=20005;
					frenum[w][0]=0;
					frenum[w][2]=fre[w][0]-fre[w][2];
					anum++;
				}
				else
				{
					sum=sum-frenum[w][2];
					frenum[w][1]=20005;
					frenum[w][2]=0;
					frenum[w][0]=fre[w][2]-fre[w][0];
					cnum++;
				}
			}
			
		}
		if(cnum>n/2)
		{
			//cout<<anum;
			long long x=cnum-n/2,tong[20005]={};
			for(long long j=1;j<=x;j++)
			{
				long long minn=200005;
				long long w,wx;
				for(long long k=1;k<=n;k++)
				{
					if(tong[k]==0&&frenum[k][2]==0)
					{
						if(minn>min(frenum[k][1],frenum[k][0]))
						{
							minn=min(frenum[k][1],frenum[k][0]);
							w=k;
							if(min(frenum[k][1],frenum[k][0])==frenum[k][1])
							{
								wx=1;
							}
							else
							{
								wx=0;
							}
						}
					}
				}
				tong[w]++;
				anum--;
				//cout<<1<<w;
				if(wx==1)
				{
					
					sum=sum-frenum[w][1];
					frenum[w][2]=20005;
					frenum[w][1]=0;
					frenum[w][0]=fre[w][1]-fre[w][0];
					bnum++;
				}
				else
				{
					sum=sum-frenum[w][0];
					frenum[w][2]=20005;
					frenum[w][0]=0;
					frenum[w][1]=fre[w][0]-fre[w][1];
					anum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
