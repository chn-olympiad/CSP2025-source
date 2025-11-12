#include<bits/stdc++.h>
using namespace std;
int t,a[100000][3],num=0,xm[3]={0},ma=-1,mab,numk[100000][2],numj=0,mi=100000,mib,numpt,numptb,zs[5];//mab标号，xm项目,numk存储每个值 ,numj计数 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
			for(int l=0;l<2;l++)
				numk[j][l]=0;
		numj=0;
		for(int j=0;j<3;j++)
			xm[j]=0;
		for(int j=0;j<n;j++)
			for(int l=0;l<3;l++)
				cin>>a[j][l];
		for(int j=0;j<n;j++)
		{	
			for(int l=0;l<3;l++)
				if(ma<a[j][l])
				{
					ma=a[j][l];
					mab=l;
				}
			for(int l=0;l<3;l++)
			{
				if(xm[l]>=n/2&&mab==l)
				{
					for(int k=0;k<numj;k++)
					{
						if(mi>numk[k][0])
						{
							mi=numk[k][0];
							mib=k;
						}
					}
					if(num<=num-mi+ma)
					{
						num=num-mi+ma;
						numk[mib][0]=ma;
						numk[mib][1]=j;
						ma=-1;
						mi=100000;
						continue;
					}
					else
					{
						numpt=num;
						for(int k=0;k<3;k++)
						{
							if(k==mab)
								continue;
							if(numpt<num-mi+ma+a[numk[mib][1]][k])
							{
								numpt=num-mi+ma+a[numk[mib][1]][k];
								numptb=k;
							}
						}
						num=numpt;
						xm[ma]--;
						xm[numptb]++;
						numk[mib][0]=a[numk[mib][1]][numptb];
						ma=-1;
						mi=100000;
						continue;
					}
				}
			}
			num+=ma;
			numk[numj][0]=ma;
			numk[numj][1]=j;
			numj++;
			xm[mab]++;
			ma=-1;
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
