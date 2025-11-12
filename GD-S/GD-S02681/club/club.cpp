#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int b1[N],b2[N],b3[N];
int cnt,MAXN,MAXNN;
int CY[5];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		int a;
		cin>>a;
		/*
		if(a<=30)
		{
			for(int j=1;j<=a;j++)
			{
				cin>>b1[j]>>b2[j]>>b3[j];
			
				for(int k=1;k<=1;k++)
				{
					if(b1[j]>=b2[j])
					{
						if(b1[j]>=b3[j])
						{
							MAXN=b1[j];
							CY[1]++;
							break;
						}
					}
					if(b2[j]>=b1[j])
					{
						if(b2[j]>=b3[j])
						{
							MAXN=b2[j];
							CY[2]++;
							break;
						}
					}
					MAXN=b3[j];
					CY[3]++;
				}
				cnt+=MAXN;
				if(CY[1]||CY[2]||CY[3]>a/2)
				{
					cnt=a/2;
				}
			}
		}
		*/
		
		for(int j=1;j<=a;j++)
		{
			cin>>b1[j]>>b2[j]>>b3[j];
			
			for(int k=1;k<=1;k++)
			{
				if(b1[j]>=b2[j])
				{
					if(b1[j]>=b3[j])
					{
						MAXN=b1[j];
						CY[1]++;
						break;
					}
				}
				if(b2[j]>=b1[j])
				{
					if(b2[j]>=b3[j])
					{
						MAXN=b2[j];
						CY[2]++;
						break;
					}
				}
				MAXN=b3[j];
				CY[3]++;
			}
			cnt+=MAXN;
		}
		if(CY[1]<=(a/2)+1&&CY[2]<=(a/2)+1&&CY[3]<=(a/2)+1)
			{
				cout<<cnt<<endl;
				continue;
			}
			else
			{
				if(CY[1]>a/2)
				{
					MAXNN=CY[1]-a/2;
					cnt-=MAXNN;
					cout<<cnt+1<<endl;
					continue;
				}
				if(CY[2]>a/2)
				{
					MAXNN=CY[2]-a/2;
					cnt-=MAXNN;
					cout<<cnt+1<<endl;
					continue;
				}
				if(CY[3]>a/2)
				{
					MAXNN=CY[3]-a/2;
					cnt-=MAXNN;
					cout<<cnt+1<<endl;
					continue;
				}
			}
		//cout<<cnt<<endl;
		//cout<<CY[1]<<" "<<CY[2]<<" "<<CY[3];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
