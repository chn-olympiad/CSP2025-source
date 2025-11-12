#include<bits/stdc++.h>
using namespace std;
long long a[105][105],n,m,b[105],xm=1,c;
long long dx[4]={0,0,1,0},dy[4]={-1,1,0,0};
void f(long long x,long long y,long long k)
{
	if(k==xm)
	{
		cout<<x<<" "<<y;
		return ;
	}
	int bo=1;
	for(int i=0;i<3;i++)
	{
		long long tx=x+dx[i],ty=y+dy[i];
		if(tx>=1 && tx<=n && ty>=1 && ty<=m && bo==1 && a[tx][ty]==0)
		{
			k++;
			a[tx][ty]=k;
			bo=-1;
			f(tx,ty,k);
		}
	}
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(b[i]>b[1])
			xm++;
	}
	a[1][1]=1;
	f(1,1,1);
	return 0;
}