#include<bits/stdc++.h>
using namespace std;
const int _=1e5+5;
struct hp{
	int p,m,d;
}a[3*_];
int t,n,qwq[4],cnt;
int mm[_][4];
long long ans=0;
long long dp[205][205][205];
bool b[_];
bool cmp(hp x,hp y)
{
	return x.d>y.d;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	cin>>t;
	while(t--)
	{
		memset(b,0,sizeof(b));
		memset(qwq,0,sizeof(qwq));
		memset(dp,0,sizeof(dp));
		cnt=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[++cnt].d;
				a[cnt].m=i,a[cnt].p=j;
				mm[i][j]=a[cnt].d;
			}
		}
		if(n<=100)
		{
//			cout<<"!!!\n";
			for(int i=1;i<=n;i++)
			{
				for(int j=n/2;j>=0;j--)
				{
					for(int k=n/2;k>=0;k--)
					{
						for(int l=n/2;l>=0;l--)
						{
							long long sum=0;
							if(j>0) sum=max(sum,dp[j-1][k][l]+mm[i][1]);
							if(k>0) sum=max(sum,dp[j][k-1][l]+mm[i][2]);
							if(l>0) sum=max(sum,dp[j][k][l-1]+mm[i][3]);
							dp[j][k][l]=max(dp[j][k][l],sum);
						}
					}
				}
			}
			cout<<dp[n/2][n/2][n/2]<<endl;
			continue;
		}
		sort(a+1,a+1+cnt,cmp);
//		for(int i=1;i<=cnt;i++)
//		{
//			cout<<a[i].m<<" "<<a[i].p<<" "<<a[i].d<<"\n";
//		}
		for(int i=1;i<=n;i++)
		{
			if(qwq[a[i].p]<=n/2&&b[a[i].m]==0)
			{
				qwq[a[i].p]++;
				ans+=a[i].d;
				b[a[i].m]=1;
			}
		}
		long long awa=0,T=1e8/(t*n)/6;
		while(T>0)
		{
			T--;
			memset(b,0,sizeof(b));
			memset(qwq,0,sizeof(qwq));
			long long awa=0;
			int hhh=rand()%n+1,hhh2=rand()%n+1;
//			cout<<hhh<<" "<<hhh2<<endl;
			swap(a[hhh],a[hhh2]);
			for(int i=1;i<=n;i++)
			{
				if(qwq[a[i].p]<=n/2&&b[a[i].m]==0)
				{
					qwq[a[i].p]++;
					awa+=a[i].d;
					b[a[i].m]=1;
				}
			}
			ans=max(awa,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1968459
2230409
2393817
1969056
2284933

1968459
2230409
2393817
2253478
2284933

*/
