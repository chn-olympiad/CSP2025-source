#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,a[N][3],c[3],sum,b[3][N];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		c[0]=c[1]=c[2]=sum=0;
		for(int i=1;i<=n;i++)
		{
			int mx=-1,idx;
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>mx) mx=a[i][j],idx=j;
			}
			sum+=mx;
			b[idx][++c[idx]]=-N;
			for(int j=0;j<3;j++)
			{
				if(j!=idx)
				{
					b[idx][c[idx]]=max(b[idx][c[idx]],a[i][j]-mx);
				}
			}
		}
		if((c[0]<<1)<=n&&(c[1]<<1)<=n&&(c[2]<<1)<=n)
		{
			cout<<sum<<"\n";
			continue;
		}
		int idx;
		for(int i=0;i<3;i++)
		{
			if((c[i]<<1)>n)
			{
				idx=i;
				break;
			}
		}
		sort(b[idx]+1,b[idx]+c[idx]+1,cmp);
		for(int i=1;i<=c[idx]-(n>>1);i++) sum+=b[idx][i];
		cout<<sum<<"\n";
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0

*/
