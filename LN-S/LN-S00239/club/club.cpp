#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int cnt1;
	int cnt2;
	int cnt3;
	int n[t+5];
	int a[10][5];
	int sum=0;
	int maxx[10000];
	int t1;
	for(int m=1;m<=t;m++)
	{
		sum=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cin>>n[m];
		for(int i=1;i<=n[m];i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				maxx[i]=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				maxx[i]=a[i][2];
			}
			else
			{
				maxx[i]=a[i][3];
			}
		}
		for(int i=1;i<=n[m];i++)
		{
			for(int j=2;j<=n[m];j++)
			{
				if(maxx[j]<maxx[j-1])
				{
					t1=a[j][1];
					a[j][1]=a[j-1][1];
					a[j-1][1]=t1;
					t1=a[j][2];
					a[j][2]=a[j-1][2];
					a[j-1][2]=t1;
					t1=a[j][3];
					a[j][3]=a[j-1][3];
					a[j-1][3]=t1;
				}
			}
		}
		for(int i=1;i<=n[m];i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				cnt1++;
				if(cnt1<=n[m]/2)
				{
					sum+=a[i][1];
				}
				else
				{
					cnt1--;
					sum+=max(a[i][2],a[i][3]);
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				cnt2++;
				if(cnt2<=n[m]/2)
				{
					sum+=a[i][2];
				}
				else
				{
					cnt2--;
					sum+=max(a[i][1],a[i][3]);
				}
			}
			else
			{
				cnt3++;
				if(cnt3<=n[m]/2)
				{
					sum+=a[i][3];
				}
				else
				{
					cnt3--;
					sum+=max(a[i][1],a[i][2]);
				}
			}
		}
			cout<<sum<<endl;
	}
	return 0;
}
