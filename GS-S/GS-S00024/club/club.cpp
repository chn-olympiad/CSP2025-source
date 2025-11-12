#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct st
{
	int x,y,z;
}j;
struct  mk
{
	int sx,sy,sz,sum;	
}mr[100005][3];
int lt(int e,int f,int g)
{
	if(max(e,max(f,g))==e)	return 0;
	else if(max(e,max(f,g))==f)	return 1;
	else return 2;
}
int t,n,ans,sd,k;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	mr[0][0].sx=0;
	mr[0][0].sy=0;
	mr[0][0].sz=0;
	mr[0][0].sum=0;
	mr[0][1].sx=0;
	mr[0][1].sy=0;
	mr[0][1].sz=0;
	mr[0][1].sum=0;
	mr[0][2].sx=0;
	mr[0][2].sy=0;
	mr[0][2].sz=0;
	mr[0][2].sum=0;
	while(t--)
	{
		cin>>n;
		sd=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>j.x>>j.y>>j.z;
			k=lt(mr[i-1][0].sum,mr[i-1][1].sum,mr[i-1][2].sum);
			if(mr[i-1][k].sx<sd)
			{
				mr[i][0].sum=mr[i-1][k].sum+j.x;
				mr[i][0].sx=mr[i-1][k].sx+1;
				mr[i][0].sy=mr[i-1][k].sy;
				mr[i][0].sz=mr[i-1][k].sz;
			}
			else	mr[i][0].sum==-1;
			if(mr[i-1][k].sy<sd)
			{
				mr[i][1].sum=mr[i-1][k].sum+j.y;
				mr[i][1].sx=mr[i-1][k].sx;
				mr[i][1].sy=mr[i-1][k].sy+1;
				mr[i][1].sz=mr[i-1][k].sz;
				
			}
			else	mr[i][1].sum==-1;
			if(mr[i-1][k].sz<sd)
			{
				mr[i][2].sum=mr[i-1][k].sum+j.z;
				mr[i][2].sx=mr[i-1][k].sx;
				mr[i][2].sy=mr[i-1][k].sy;
				mr[i][2].sz=mr[i-1][k].sz+1;
				
			}
			else	mr[i][2].sum==-1;
		}
		cout<<max(mr[n][0].sum,max(mr[n][1].sum,mr[n][2].sum))<<'\n';
	}
	return 0;
}
