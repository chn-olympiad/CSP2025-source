#include<bits/stdc++.h>
using namespace std;
int t,n;
int c1[100005]={},c2[100005]={},c3[100005]={},c1n=0,c2n=0,c3n=0,ans=0,ansh1[100005]={},ansh2[100005]={},ansh3[100005]={},s=1005,sa=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		c1n=0;
		c2n=0;
		c3n=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>c1[i]>>c2[i]>>c3[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(c1[i]>=c2[i]&&c1[i]>=c3[i])
			{
				if(c1n<n/2)
				{
					ansh1[i]=c1[i];
					c1n++;
					ans+=c1[i];
				}
				else
				{
					s=1005;
					sa=0;
					for(int j=1;j<=i;j++)
					{
						if(ansh1[j]<s&&ansh1[j]>0)
						{
							s=ansh1[j];
							sa=j;
						}
					}
					if(s<c1[i])
					{
						ans-=ansh1[sa];
						ansh1[sa]=0;
						ansh1[i]=c1[i];
						ans+=c1[i];
					}
				}
				
			}
			else if(c2[i]>=c1[i]&&c2[i]>=c3[i])
			{
				if(c2n<n/2)
				{
					ansh2[i]=c2[i];
					c2n++;
					ans+=c2[i];
				}
				else
				{
					s=1005;
					sa=0;
					for(int j=1;j<=i;j++)
					{
						if(ansh2[j]<s&&ansh2[j]>0)
						{
							s=ansh2[j];
							sa=j;
						}
					}
					if(s<c2[i])
					{
						ans-=ansh2[sa];
						ansh2[sa]=0;
						ansh2[i]=c2[i];
						ans+=c2[i];
					}
				}
				
			}
			else if(c3[i]>=c1[i]&&c3[i]>=c2[i])
			{
				if(c3n<n/2)
				{
					ansh3[i]=c3[i];
					c3n++;
					ans+=c3[i];
				}
				else
				{
					s=1005;
					sa=0;
					for(int j=1;j<=i;j++)
					{
						if(ansh3[j]<s&&ansh3[j]>0)
						{
							s=ansh3[j];
							sa=j;
						}
					}
					if(s<c3[i])
					{
						ans-=ansh3[sa];
						ansh3[sa]=0;
						ansh3[i]=c3[i];
						ans+=c3[i];
					}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}