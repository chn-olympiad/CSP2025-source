#include <bits/stdc++.h>
using namespace std;
int t,n,a[100007],b[100007],c[100007],as,bs,cs;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		as=n/2;
		bs=n/2;
		cs=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i] && a[i]>c[i])
			{
				if(as>0)
				{
					as--;
					ans+=a[i];
				}
				else
				{
					if(b[i]>c[i] && bs>0)
					{
						bs--;
						ans+=b[i];
					}
					else
					{
						cs--;
						ans+=c[i];
					}
				}
			}
			else if(b[i]>a[i] && b[i]>c[i])
			{
				if(bs>0)
				{
					bs--;
					ans+=b[i];
				}
				else
				{
					if(a[i]>c[i] && as>0)
					{
						as--;
						ans+=a[i];
					}
					else
					{
						cs--;
						ans+=c[i];
					}
				}
			}
			else
			{
				if(cs>0)
				{
					cs--;
					ans+=c[i];
				}
				else
				{
					if(a[i]>b[i] && as>0)
					{
						as--;
						ans+=a[i];
					}
					else
					{
						bs--;
						ans+=b[i];
					}
				}
			}
		}		
		cout<<ans<<endl;
	}
}
