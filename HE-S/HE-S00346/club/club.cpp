#include<bits/stdc++.h>
using namespace std;
const int N=35;
int t,n,g[N][5];
int f[N][N][N][N];
int maxn;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int op=1;op<=t;op++)
	{
		for(int i=0;i<=N-1;i++) for(int a=0;a<=N-1;a++) for(int b=0;b<=N-1;b++) for(int c=0;c<=N-1;c++) f[i][a][b][c]=0;
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>g[i][j];
		int maxn=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int a=0;a<=i;a++)
			{
				for(int b=0;b<=i;b++)
				{
					if(a+b>i||a>maxn||b>maxn) break;
					for(int c=0;c<=i;c++)
					{
						if(a+b+c>i||c>maxn) break;
						if(a>0) f[i][a][b][c]=max(f[i][a][b][c],f[i-1][a-1][b][c]+g[i][1]);
						if(b>0) f[i][a][b][c]=max(f[i][a][b][c],f[i-1][a][b-1][c]+g[i][2]);
						if(c>0) f[i][a][b][c]=max(f[i][a][b][c],f[i-1][a][b][c-1]+g[i][3]);
						//cout<<i<<' '<<a<<' '<<b<<' '<<c<<' '<<f[i][a][b][c]<<endl;
					}
				}
			}
		}
		int ans=0;
		for(int a=0;a<=maxn;a++)
		{
			for(int b=0;b<=maxn;b++)
			{
				for(int c=0;c<=maxn;c++)
				{
					ans=max(ans,f[n][a][b][c]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
3 5 1
5 3 4
*/ 
