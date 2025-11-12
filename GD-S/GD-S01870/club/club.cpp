#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010][5],x1,x2,x3,y1[100010],y2[100010],y3[100010],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		x1=0,x2=0,x3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				x1++;
				ans+=a[i][1];
				y1[x1]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				x2++;
				ans+=a[i][2];
				y2[x2]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else
			{
				x3++;
				ans+=a[i][3];
				y3[x3]=a[i][3]-max(a[i][2],a[i][1]);
			}
		}
		if(max(max(x1,x2),x3)<=n/2)
		{
			cout<<ans<<endl;
		}
		else
		{
			if(x1>=x2&&x1>=x3)
			{
				sort(y1+1,y1+x1+1);
				for(int i=1;i<=x1-n/2;i++)
				{
					ans-=y1[i];
				}
			}
			else if(x2>=x1&&x2>=x3)
			{
				sort(y2+1,y2+x2+1);
				for(int i=1;i<=x2-n/2;i++)
				{
					ans-=y2[i];
				}
			}
			else
			{
				sort(y3+1,y3+x3+1);
				for(int i=1;i<=x3-n/2;i++)
				{
					ans-=y3[i];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
