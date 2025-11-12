#include <bits/stdc++.h>
using namespace std;
int a1[100010],a2[100010],a3[100010];
int main()
{
	int t;
	cin>>t;
	int y=0,s=0,e=0;
	bool f=true;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a1[i]>=a2[i]&&a1[i]>=a3[i])
				y++;
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i])
				e++;
			else 
				s++;
		}
		for(int i=1;i<=n;i++)
		{
			if(y<=n/2&&e<=n/2&&s<=n/2)
			{
				int g=max(a1[i],a2[i]);
				ans+=max(g,a3[i]);
			}
			if(y>n/2)
			{
				if(a2[i]>=a3[i])
				{
					e++;
					if(e>n/2)
					{
						ans+=a3[i];
					}
					ans+=a2[i];
				}
				ans+=a1[n-i+1];
			}
			else if(e>n/2)
			{
				if(a1[i]>=a3[i])
				{
					y++;
					if(y>n/2)
					{
						ans+=a3[i];
					}
					ans+=a1[i];
				}
				ans+=a2[n-i+1];
			}
			else if(s>n/2)
			{
				if(a2[i]>=a1[i])
				{
					y++;
					if(y>n/2)
					{
						ans+=a1[i];
					}
					ans+=a2[i];
				}
			}
		}
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cout<<ans<<endl;
		y=0,s=0,e=0;
	}
	return 0;
}
