#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;

int cnt,cntt;
int cntn,cntw,cntr;
int t,maxx=-1;
int n,ans;
int a[N][5],d[N],one[N],two[N],three[N];
int cntx[N];
int maxn,maxw,maxr;//分别是第一、二、三个各部门的最大值 

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		{
			int maxp=-1,maxo=-1,maxq=-1;
			int ansx=-1;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=3;j++)
					cin>>a[i][j];
			maxo=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			maxp=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			maxq=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			ansx=max(maxo,max(maxp,maxq));
			cout<<ansx<<endl;
		}
		if(n==4)
		{
			int maxp=-1,maxo=-1,maxq=-1;
			int ansx=-1;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
					
			maxo=max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),
			max(max(a[1][1]+a[3][2],a[1][1]+a[3][3]),
			max(a[1][1]+a[4][2],a[1][1]+a[4][3])));
			
			maxp=max(max(a[1][2]+a[2][1],a[1][2]+a[2][3]),
			max(max(a[1][2]+a[3][1],a[1][2]+a[3][3]),
			max(a[1][2]+a[4][1],a[1][2]+a[4][3])));
			
			maxq=max(max(a[1][3]+a[2][1],a[1][3]+a[2][2]),
			max(max(a[1][3]+a[3][1],a[1][3]+a[3][2]),max(a[1][3]+a[4][1],a[1][3]+a[4][2])));
			
			ansx=max(maxo,max(maxp,maxq));
			cout<<ansx<<endl;
		}	
		
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
					one[i]=a[i][1];
					two[i]=a[i][2];
					three[i]=a[i][3];
				}
			}
			if(a[100][2]==a[100][3]==0)
			{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
					d[i]=a[i][j];
				}		
			}
			sort(d+1,d+1+n);
			for(int i=n;i>=1;i--)
			{
				ans+=d[i];
				if(i==n/2) break;
			}
			cout<<ans<<endl;
			}
			else{
				sort(one+1,one+1+n);
			sort(two+1,two+1+n);
			sort(three+1,three+1+n);
			for(int i=n;i>=n/2;i--)
			{
				ans+=one[i];
				ans+=two[i];
				ans+three[i];
			}
			cout<<ans<<endl;
			}
			
		}
	}
	

	return 0;
}

	

		

/*
Ren5Jie4Di4Ling5%
*/
