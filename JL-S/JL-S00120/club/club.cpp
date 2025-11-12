#include<bits/stdc++.h>
using namespace std;
int xi[100000][5];
int ji[3]={0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		int n,zj[3]={0},zzj1=0;
		cin>>n;
		for(int q=0;q<n;q++)
		{
			cin>>xi[q][1];
			cin>>xi[q][2];
			cin>>xi[q][3];
			int dj=0;
			if(xi[q][1]>=xi[q][2]&&xi[q][2]>=xi[q][3])
			{
				ji[1]=3;
				ji[2]=2;
				ji[3]=1;
				dj=xi[q][1];
				zj[1]++;
				if(zj[1]-1>=n/2&&zj[2]<n/2)
				{
					zj[1]--;
					zj[2]++;
					dj=xi[q][2];
				}else if(zj[1]-1>=n/2&&zj[2]>=n/2)
					{
						zj[1]--;
						zj[3]++;
						dj=xi[q][3];
					}
				}
			if(xi[q][1]<=xi[q][2]&&xi[q][2]<=xi[q][3])
			{
				ji[1]=1;
				ji[2]=2;
				ji[3]=3;
				dj=xi[q][3];
				zj[3]++;
				if(zj[3]-1>=n/2&&zj[2]<n/2)
				{
					zj[3]--;
					zj[2]++;
					dj=xi[q][2];
				}else if(zj[3]-1>=n/2&&zj[2]>=n/2)
					{
						zj[3]--;
						zj[1]++;
						dj=xi[q][1];
					}
			}
			if(xi[q][2]>=xi[q][1]&&xi[q][1]>=xi[q][3])
			{
				ji[1]=2;
				ji[2]=3;
				ji[3]=1;
				dj=xi[q][2];
				zj[2]++;
				if(zj[2]-1>=n/2&&zj[1]<n/2)
				{
					zj[2]--;
					zj[1]++;
					dj=xi[q][1];
				}else if(zj[2]-1>=n/2&&zj[1]>=n/2)
					{
						zj[2]--;
						zj[3]++;
						dj=xi[q][3];
					}
			}
			if(xi[q][1]>=xi[q][3]&&xi[q][3]>=xi[q][2])
			{
				ji[1]=3;
				ji[2]=1;
				ji[3]=2;
				dj=xi[q][1];
				zj[1]++;
				if(zj[1]-1>=n/2&&zj[3]<n/2)
				{
					zj[1]--;
					zj[3]++;
					dj=xi[q][3];
				}else if(zj[1]-1>=n/2&&zj[3]>=n/2)
					{
						zj[1]--;
						zj[2]++;
						dj=xi[q][2];
					}
			}
			if(xi[q][3]>=xi[q][1]&&xi[q][1]>=xi[q][2])
			{
				ji[1]=2;
				ji[2]=1;
				ji[3]=3;
				dj=xi[q][3];
				zj[3]++;
				if(zj[3]-1>=n/2&&zj[1]<n/2)
				{
					zj[3]--;
					zj[1]++;
					dj=xi[q][1];
				}else if(zj[3]-1>=n/2&&zj[1]>=n/2)
					{
						zj[1]--;
						zj[2]++;
						dj=xi[q][2];
					}
			}
			zzj1=zzj1+dj;
		}
			cout<<zzj1<<endl;
		
	}
	return 0;
}
