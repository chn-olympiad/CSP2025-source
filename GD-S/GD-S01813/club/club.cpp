#include <bits/stdc++.h>
using namespace std;
int n,t,ans,bm1=0,bm2=0,bm3=0;
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int a[n+5][5],b[n+5],ans=0;	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				b[i]=false;
			}
		}
		for(int i=1;i<=n;i++)
		{	
			if(b[i] == false && a[i][1] > a[i][2] && a[i][1] > a[i][3] && bm1 < n/2) 
			{
				bm1+=1;
				b[i]=true;
				ans+=a[i][1];
				continue;
			}	
			else if(b[i] == false && a[i][2] > a[i][1] && a[i][2] > a[i][3] && bm2 < n/2) 
			{
				bm2+=1;
				b[i]=true;
				ans+=a[i][2];
				continue;
			}
			else 
			{
				bm3+=1;
				b[i]=true;
				ans+=a[i][3];
				continue;
			}
		}
	cout<<ans;
	}
	return 0;
}
