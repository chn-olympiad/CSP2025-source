#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3];
int q[3];
int mx=0;
void f(int x,int tot)
{
	if(x>=n+1)
	{
		if(tot>=mx)
			mx=tot;
		return;
	}
	for(int i=0;i<=2;i++)
	{
		if(q[i]==0)
			continue;
		else
		{
			q[i]=q[i]-1;
			f(x+1,tot+a[x][i]);
			q[i]=q[i]+1;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		mx=0;
		scanf("%d",&n);
		q[0]=n/2;
		q[1]=n/2;
		q[2]=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			f(1,0);
		}
		printf("%d\n",mx);
		for(int i=1;i<=n;i++)
		{
			a[i][0]=0;
			a[i][1]=0;
			a[i][2]=0;
		}
	}
	return 0;
 } 
