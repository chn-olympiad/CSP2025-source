#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,res;
int r[N*N],g[N][N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>r[i];
	}
	res=r[1];
	sort(r+1,r+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			int j=1;
			while(j<=n)
			{
				g[i][j]=r[cnt];
				cnt++;
				j++;
			}
		}
		else
		{
			int j=n;
			while(j>=1)
			{
				g[i][j]=r[cnt];
				cnt++;
				j--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==res)
			{
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	return 0;
}
