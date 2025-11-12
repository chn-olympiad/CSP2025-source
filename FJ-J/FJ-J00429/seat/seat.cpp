#include<bits/stdc++.h>
using namespace std;
const int N=11;
int a[N][N],n,m,l,r;
struct ovo{
	int p,q;
}b[N*N];
bool cmp(ovo x,ovo y)
{
	return x.p>y.p;
}
void abc()
{
	int nx=1,ny=1;
	a[nx][ny]=b[1].p;
	for(int i=2;i<=n*m;i++)
	{
		if(1<=nx&&nx<=n&&1<=ny&&ny<m&&a[nx][ny+1]==0)
			a[nx][++ny]=b[i].p;
		else if(1<=nx&&nx<n&&1<=ny&&ny==m&&a[nx+1][ny]==0)
			a[++nx][ny]=b[i].p;
		else if(1<=nx&&nx<=n&&1<ny&&ny<=m&&a[nx][ny-1]==0)
			a[nx][--ny]=b[i].p;
		if(b[i].q==1)
		{
			l=nx;
			r=ny;
			return ;
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i].p;
		b[i].q=i;
	}
	sort(b+1,b+1+(n*m),cmp);
	abc();
	cout<<l<<' '<<r;
	return 0;
}
