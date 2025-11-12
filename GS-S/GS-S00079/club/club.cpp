#include<bits/stdc++.h>

using namespace std;
int t,n,x,y,z,q;
const int N = 2e4+5;
const int M = 1e2+5;
struct s
{
	int a,b,c;
}p[N];
bool cmp(s x,s y)
{
	return x.a > y.a ;
}
int dp[4][M],dp1[M];
int bi(int a,int b,int c,int d)
{
	int mx=-1,mx1=-1,mx2=-1;
	mx = max(a,b);
	mx1 = max(c,d);
	mx2 = max(mx,mx1);
	return mx2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int flag = -1;
		cin >> n;
		int w = n / 2;
		for(int i = 1;i <= n;i++)
		{
			cin >> p[i].a >> p[i].b >> p[i].c;
			if(p[i].c!=0||p[i].b!=0)
				flag = -2;
		}
		if(n==2)
		{
			int o = p[1].a + p[2].b;
			int oo = p[1].a + p[2].c;
			int ooo = p[1].b + p[2].a;
			int oooo =p[1].b + p[2].c;
			int ooooo =p[1].c + p[2].a;
			int oooooo =p[1].c + p[2].b;
			cout << max(max(max(o,oo),max(ooo,oooo)),max(ooooo,oooooo)) << endl;
			continue;
		}
		if(flag == -1)
		{
			sort(p+1,p+1+n,cmp);
			int gg = 0;
			for(int i = 1;i <= w;i++)
				gg+=p[i].a ;
			cout << gg << endl;
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = n/2;j >= 1;j--)
			{
				x = dp[1][j]+dp[2][j]+dp[3][j];
				y = dp[1][j-1]+p[i].a+dp[2][j]+dp[3][j];
				z = dp[1][j]+dp[2][j-1]+p[i].b+dp[3][j];
				q = dp[1][j]+dp[2][j]+dp[3][j-1]+p[i].c;
				if(bi(x,y,z,q)==y)
				{
					dp[1][j] = dp[1][j-1]+p[i].a;
				}
				else if(bi(x,y,z,q)==z)
				{
					dp[2][j] = dp[2][j-1]+p[i].b;
				}
				else if(bi(x,y,z,q)==q)
				{
					dp[3][j] = dp[3][j-1]+p[i].c;
				}
			}
		}
		cout << dp[1][w]+dp[2][w]+dp[3][w] << endl;
		memset(dp,0,sizeof dp);
	}
	return 0;
}
