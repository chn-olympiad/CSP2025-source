#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans;
int a[N][5];
int f[5][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int n1=n/2;
		for(int k=1;k<=3;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n1;j++)
				{
					f[k][j]=max(f[k][j-1],f[k][j-1]+a[i][k]);
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			ans+=f[i][n1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
