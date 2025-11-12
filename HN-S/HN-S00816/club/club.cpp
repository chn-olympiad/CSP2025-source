#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[1000086],b[1000086],c[1000086];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int x=0,y=0,z=0;
        int m=0,mn=0,nm=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]&&a[i]>c[i]&&x<n/2)
			{
			    x++;
			    m+=a[i];
			    continue;
			}
			if(b[i]>a[i]&&b[i]>c[i]&&y<n/2)	
			{
				y++;
				mn+=b[i];
				continue;
			}
			if(c[i]>a[i]&&c[i]>b[i]&&z<n/2)
			{
			    z++;
				nm+=c[i];
				continue;
			}
			else
			{
			    if(a[i]>b[i]&&a[i]>c[i]&&x>n/2)
			    {
			        if(b[i]>c[i]&&y<n/2)
						y++;
						mn+=b[i];
						continue;
					if(c[i]>b[i]&&z<n/2)
						z++;
						nm+=c[i];
						continue;
					if(b[i]<1&&c[i]<1&&y<n/2)
						y++;
						mn+=b[i];
						continue;
					    if(b[i]<1&&c[i]<1&&z<n/2)
						    z++;
						    nm+=c[i];
						    continue;
				}
				if(b[i]>a[i]&&b[i]>c[i]&&y>n/2)
			    {
			        if(a[i]>c[i]&&x<n/2)
			        {
			        	x++;
			        	m+=a[i];
			        	continue;
					}
					if(c[i]>a[i]&&z<n/2)
					{
						z++;
						nm+=c[i];
						continue;
					}	
					if(a[i]<1&&c[i]<1&&x<n/2)
						x++;
						m+=a[i];
						continue;
					    if(b[i]<1&&c[i]<1&&z<n/2)
						    z++;
						    nm+=c[i];
						    continue;
				}
				if(c[i]>a[i]&&c[i]>b[i]&&z>n/2)
			    {
			        if(b[i]>c[i]&&y<n/2)
					{
						y++;
						mn+=b[i];
						continue;
					}	
					if(a[i]>b[i]&&x<n/2)
					{
						x++;
						m+=a[i];
						continue;
					}	
				}
			}    
		}
		cout<<m+mn+nm<<endl;
	}
	return 0;
}
