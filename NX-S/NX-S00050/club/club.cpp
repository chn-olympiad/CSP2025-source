#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
int b[100010][4];
int x1,x2,x3;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				b[i][j]=a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]<a[i][2])
			{
				swap(a[i][1],a[i][2]); 
			}
			if(a[i][2]<a[i][3])
			{
				swap(a[i][2],a[i][3]); 
			}
			if(a[i][1]<a[i][2])
			{
				swap(a[i][1],a[i][2]); 
			}
			ans+=a[i][1];
			for(int j=1;j<=3;j++)
			{
			if(a[i][1]==b[i][j])
			{
				if(j==1)
				{
					x1++;
				}
				if(j==2)
				{
					x2++;
				}
				if(j==3)
				{
					x3++;
				}
			}
			}

		}
			if(x1>n/2||x2>n/2||x3>n/2)
			{
				
				
			}
			else
			{
				cout<<ans<<endl;
			}

	}
    return 0;
}
