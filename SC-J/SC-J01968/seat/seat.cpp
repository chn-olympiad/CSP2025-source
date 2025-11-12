#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=20;
int mj,xb,dt[M][M],fzdl[N],dl[N],xr,n,m,x,y,dlsi;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	dlsi=n*m;
	for(int i=1;i<=dlsi;i++)
	{
		cin>>dl[i];
	}
	xr=dl[1];
	sort(dl+1,dl+1+dlsi);
	for(int i=dlsi;i>=1;i--)
	{
		fzdl[dlsi-i+1]=dl[i];
	}
	for(int i=1;i<=dlsi;i++)
	{
		if(fzdl[i]==xr)
		{
			xb=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				mj++;
				if(mj==xb)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				mj++;
				if(mj==xb)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}