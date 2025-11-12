#include<bits/stdc++.h>
using namespace std;
int cim(int a,int b,int c)
{
	int m[4];
	m[1]=a;
	m[2]=b;
	m[3]=c;
	sort(m+1,m+4);
	if(m[2]==a)
	{
		return 1;
	}
	if(m[2]==b)
	{
		return 2;
	}
	if(m[2]==c)
	{
		return 3;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int ci=1;ci<=t;ci++)
	{
		cin>>n;
		int a[n+2][5];
		int x[n+2][3];
		for(int i=1;i<=n;i++)
		{
			int tmp1=0,tmp2=0,tmp3=0;
			cin>>a[i][1];
			if(tmp1<a[i][1])
			{
				tmp1=1;
			}
			cin>>a[i][2];
			if(tmp1<a[i][2])
			{
				tmp1=2;
			}
			cin>>a[i][3];
			if(tmp1<a[i][3])
			{
				tmp1=3;
			}
			x[i][1]=tmp1;
			x[i][2]=cim(a[i][1],a[i][2],a[i][3]);
		}
		int ans=0,A=0,B=0,C=0,r=n/2;
		for(int i=1;i<=n;i++)
		{
			if(x[i][1]==1)
			{
				if(A<=r)
				{
					ans+=a[i][1];
					A++;
				}
				else if(x[i][2]==2&&B<=r)
				{
					ans+=a[i][2];
					B++;
				}
				else if(x[i][2]==3&&C<=r)
				{
					ans+=a[i][3];
					C++;
				}
				else
				{
					ans+=a[i][6-x[i][1]-x[i][2]];
				}
			}
			if(x[i][1]==2)
			{
				if(B<=r)
				{
					ans+=a[i][2];
					B++;
				}
				else if(x[i][2]==1&&A<=r)
				{
					ans+=a[i][1];
					A++;
				}
				else if(x[i][2]==3&&C<=r)
				{
					ans+=a[i][3];
					C++;
				}
				else
				{
					ans+=a[i][6-x[i][1]-x[i][2]];
				}
			}
			if(x[i][1]==3)
			{
				if(C<=r)
				{
					ans+=a[i][3];
					C++;
				}
				else if(x[i][2]==2&&B<=r)
				{
					ans+=a[i][2];
					B++;
				}
				else if(x[i][2]==1&&A<=r)
				{
					ans+=a[i][1];
					A++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
