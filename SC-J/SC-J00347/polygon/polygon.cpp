#include<bits/stdc++.h>
#define N 998244353
#define M 5010
using namespace std;
int n,cnt;
int u[M];
int a[M][M];
int b[M][M];

bool ch(int t,int j,int ry)
{
	if(t>j*2)
	{
		return 1;
	}
	return 0;
}
bool bll[M];
void acw(int q,int r,int mx,int xin)
{
	if(r>=3)
	{
		if(ch(q,mx,r))
		{
			cnt++;
			cnt%=N;
		}
	}
	if(r==n)
	{
		return;
	}
	for(int i=xin+1;i<=n;i++)
	{
		if(!bll[i])
		{
			bll[i]=1;
			q+=u[i];
			acw(q,r+1,max(mx,u[i]),u[i]);
			q-=u[i];
			bll[i]=0;
		}
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
	}
	for(int j=1;j<=n;j++)
	{
		int q[M];
		q[1]=j;
		bll[j]=1;
		acw(j,1,j,j);
		for(int ii=1;ii<=n;ii++)
		{
			bll[ii]=0;
		}
	}
	cout<<cnt%N;
	return 0;
}