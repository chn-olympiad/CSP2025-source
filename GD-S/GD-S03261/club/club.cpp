#include<bits/stdc++.h>
using namespace std;
long long a[100005][5];
int zz[100005];
long long b[100005],x=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int gs1=0,gs2=0,gs3=0;
		long long ans=0;
		for (int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if (a[j][1]>=a[j][2]&&a[j][1]>=a[j][3])
			{
				zz[j]=1;
				gs1=gs1+1;
				ans=ans+a[j][1];
			}
			else
			{
				if (a[j][2]>=a[j][3])
				{
					zz[j]=2;
					gs2=gs2+1;
					ans=ans+a[j][2]; 
				}
				else
				{
					zz[j]=3;
					gs3=gs3+1;
					ans=ans+a[j][3];
				}
			}
		}
		x=0;
		if (gs1>n/2)
		{
			for (int j=1;j<=n;j++)
			{
				if (zz[j]==1)
				{
					int ma=(a[j][1]-max(a[j][2],a[j][3]));
					x=x+1;
					b[x]=ma;
				}
			}
			sort(b+1,b+x+1);
			for (int i=1;i<=gs1-n/2;i++)
			{
				ans=ans-b[i];
			}
		}
		if (gs2>n/2)
		{
			for (int j=1;j<=n;j++)
			{
				if (zz[j]==2)
				{
					int ma=(a[j][2]-max(a[j][1],a[j][3]));
					x=x+1;
					b[x]=ma;
				}
			}
			sort(b+1,b+x+1);
			for (int i=1;i<=gs2-n/2;i++)
			{
				ans=ans-b[i];
			}
		}
		if (gs3>n/2)
		{
			for (int j=1;j<=n;j++)
			{
				if (zz[j]==3)
				{
					int ma=(a[j][3]-max(a[j][2],a[j][1]));
					x=x+1;
					b[x]=ma;
				}
			}
			sort(b+1,b+x+1);
			for (int i=1;i<=gs3-n/2;i++)
			{
				ans=ans-b[i];
			}
		}
		cout<<ans<<endl;
	}
 } 
