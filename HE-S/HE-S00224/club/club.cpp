#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		int m;
		int b1,c1,d1;
		cin>>m;
		int bx;
		int by;
		for(int j=1;j<=m;j++)
		{
			int mx=0;
			int b=0,c=0,d=0;
			for(int k=1;k<=3;k++)
			{
				cin>>a[k];
				if(k==1)
			{
				b++;
				b1=b;
			}
			else if(k==2)
			{
				c++;
				c1=c;
			}
			else
			{
				d++;
				d1=d;
			}
			}
			sort(a+1,a+4);
			ans+=a[3];
			bx=a[2];
			by=a[1];
		}
		if(b1>m/2||c1>m/2||d1>m/2)
			{
				ans=ans-a[3]+bx;
			}
		cout<<ans<<endl;
	}	
	return 0;
}
