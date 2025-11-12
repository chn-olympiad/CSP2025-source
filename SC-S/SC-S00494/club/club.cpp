#include<bits/stdc++.h>
using namespace std;
int t,n,cy[4][101000],ans;
int clubd(int my,int f,int s,int t,int r)
{
	if(r>n)
	{
		ans=max(ans,my);
		return 0;
	}
	if(f+1<=n/2)
	{
		clubd(my+cy[1][r],f+1,s,t,r+1);
	}
	if(s+1<=n/2)
	{
		clubd(my+cy[2][r],f,s+1,t,r+1);
	}
	if(t+1<=n/2)
	{
		clubd(my+cy[3][r],f,s,t+1,r+1);
	}
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0;
		cin>>n;
		if(n>=30)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>cy[1][i]>>cy[2][i]>>cy[3][i];	
			}
			sort(cy[1]+1,cy[1]+1+n);
			for(int i=n;i>n/2;i--)
			{
				ans+=cy[1][i];
				cy[0][i]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(!cy[0][i]) ans+=cy[2][i];
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>cy[1][i]>>cy[2][i]>>cy[3][i];	
		}
		clubd(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}