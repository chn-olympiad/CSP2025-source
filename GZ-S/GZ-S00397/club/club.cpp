//GZ-S00397 贵州省铜仁第一中学 蒲泊廷
#include<bits/stdc++.h>
using namespace std;
int a[10000][4];
void www()
{
	int n=0,c1=0,c2=0,c3=0,ans=0;
	    cin>>n;
	    for(int i=1;i<=n;i++)
	    {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
        	{
				if(c1>=n/2)
				{
					if(a[i][2]>=a[i][3] && c2<n/2)
					{
						ans+=a[i][2];
						c2++;
					}
					else
					{
						ans+=a[i][3];
						c3++;
					}
				}
				else
				{
					ans+=a[i][1];
					c1++;
				}
			}
			if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
		    {      
				if(c2>=n/2)
				{
					if(a[i][1]>=a[i][3] && c1<n/2)
					{
						ans+=a[i][1];
						c1++;
					}
					else
					{
						ans+=a[i][3];
						c3++;
					}
				}
				else
				{
					ans+=a[i][2];
					c2++;
				}
			}
			if(a[i][3]>a[i][1] && a[i][3]>a[i][2])
        	{
				if(c3>=n/2)
				{
					if(a[i][1]>=a[i][2] && c1<n/2)
					{
						ans+=a[i][1];
						c1++;
					}
					else
					{
						ans+=a[i][2];
						c2++;
					}
				}
				else
				{
					ans+=a[i][3];
					c3++;
				}
			}
		}
		cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int e=1;e<=t;e++)
	{
	    www();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

