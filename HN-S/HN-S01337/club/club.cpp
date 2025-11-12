#include<bits/stdc++.h>
using namespace std;
int a[4][100005];
int m[100005]; 
int to[100005];
int p[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0;
		for(int j=1;j<=3;j++)
			p[j]=0;
		for(int i=1;i<=n;i++)
		{
			m[i]=INT_MIN;
			for(int j=1;j<=3;j++)
			{
				cin>>a[j][i];
				if(a[j][i]>m[i])
				{
					m[i]=a[j][i];
					to[i]=j;
				}
			}
			p[to[i]]++;
			ans+=a[to[i]][i];
		}
		do
		{
			bool bol=true;
			for(int i=1;i<=3;i++)
				if(p[i]>n/2)
				{
					bol=false;
					int mi=INT_MAX;
					int mip;
					for(int j=1;j<=n;j++)
						if(a[i][j]<mi&&to[j]==i)
						{
							mi=a[i][j];
							mip=j;
						}
					int mx=INT_MIN;
					int mxp;
					for(int j=1;j<=3;j++)
						if(j!=i&&a[j][mip]<m[mip])
							if(a[j][mip]>mx)
							{
								mx=a[j][mip];
								mxp=j;
							}
					to[mip]=mxp;
					p[i]--;
					p[mxp]++;
					ans-=a[i][mip];
					ans+=mx;
					break;
				}
			if(bol)
				break;
		}
		while(114514);
		cout<<ans<<"\n";
	}
	return 0;
}
