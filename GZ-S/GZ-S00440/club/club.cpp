//GZ-S00440 贵阳市第十八中学 邹浚哲 
#include<bits/stdc++.h>
using namespace std;
const int N=200+10,M=1e5+10;
int n,T,maxx,f[N][N/2][N/2][N/2];
int ans;
struct Edge
{
	int c1,c2,c3;
}a[M];
bool cmp(Edge a,Edge b)
{
	return a.c1>b.c1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof f);
		ans=0;
		cin>>n;
		maxx=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		if(n<=202)
		{
			for(int i=1;i<=n;i++)
				for(int c1=0;c1<=i&&c1<=maxx;c1++)
					for(int c2=0;c2<=i-c1&&c2<=maxx;c2++)
						{
							int c3=i-c1-c2;
							if(c3<=maxx)
							{
								if(c1>=1)
									f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1-1][c2][c3]+a[i].c1);
								if(c2>=1)
									f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1][c2-1][c3]+a[i].c2);
								if(c3>=1)
									f[i][c1][c2][c3]=max(f[i][c1][c2][c3],f[i-1][c1][c2][c3-1]+a[i].c3);
							}
						}
			for(int c1=0;c1<=n&&c1<=maxx;c1++)
				for(int c2=0;c2<=n-c1&&c2<=maxx;c2++)
					if(n-c1-c2<=maxx)
						ans=max(f[n][c1][c2][n-c1-c2],ans);	
		}
		else
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=maxx;i++)
				ans+=a[i].c1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
