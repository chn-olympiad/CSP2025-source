//a[j][tmp[j][n-1]
#include<iostream>
using namespace std;
int a[100001][3],tmp[100001][3],ren[3];
bool clubmember[100001][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,sum;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		sum=0;
		for(int j=0;j<3;j++) ren[j]=0;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][0]>=a[j][1]&&a[j][1]>=a[j][2])
			{
				tmp[j][0]=0;tmp[j][1]=1;tmp[j][2]=2;
			}
			if(a[j][0]>=a[j][2]&&a[j][2]>=a[j][1])
			{
				tmp[j][0]=0;tmp[j][1]=2;tmp[j][2]=1;
			}
			if(a[j][1]>=a[j][0]&&a[j][0]>=a[j][2])
			{
				tmp[j][0]=1;tmp[j][1]=0;tmp[j][2]=2;
			}
			if(a[j][1]>=a[j][2]&&a[j][2]>=a[j][0])
			{
				tmp[j][0]=1;tmp[j][1]=2;tmp[j][2]=0;
			}
			if(a[j][2]>=a[j][0]&&a[j][0]>=a[j][1])
			{
				tmp[j][0]=2;tmp[j][1]=0;tmp[j][2]=1;
			}
			if(a[j][2]>=a[j][1]&&a[j][1]>=a[j][0])
			{
				tmp[j][0]=2;tmp[j][1]=1;tmp[j][2]=0;
			}
//			cout<<tmp[j][0]<<" "<<tmp[j][1]<<" "<<tmp[j][2]<<" ";
//			cout<<endl;
		}
		for(int j=0;j<n;j++)
		{
			if(j<n/2)
			{
				clubmember[j][tmp[j][0]]=1;
				ren[tmp[j][0]]++;
			}
			else
			{
				if(ren[tmp[j][0]]==n/2)
				{
					int min=20001,plc;
					int mintmp;
					for(int q=0;q<=j;q++)
					{
						if(clubmember[q][tmp[j][0]]==1)
						{
							mintmp=a[q][tmp[j][0]]-a[q][tmp[j][1]];
							if(mintmp<min)
							{
								min=mintmp;
								plc=q;
							}
						}
					}
					if(plc==j) clubmember[j][tmp[j][1]]=1;
					else
					{
						clubmember[j][tmp[j][0]]=1;
						clubmember[plc][tmp[j][0]]=0;
						clubmember[plc][tmp[j][2]]=1;
					}
				}
				else
				{
					clubmember[j][tmp[j][0]]=1;
					ren[tmp[j][0]]++;
				}
			}
//			cout<<clubmember[j][0]<<" "<<clubmember[j][1]<<" "<<clubmember[j][2]<<" ";
//			cout<<endl;
		}
		for(int j=0;j<n;j++)
		{
			sum+=clubmember[j][0]*a[j][0]+clubmember[j][1]*a[j][1]+clubmember[j][2]*a[j][2];
		}
		cout<<sum<<endl;
	}
    return 0;
}

