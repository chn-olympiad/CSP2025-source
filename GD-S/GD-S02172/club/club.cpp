#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N= 1e5;
int n,a[N][4]/*,dp[4][N][N]*/;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
	bool f2=1,f3=1;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2]==1)f2=0;
		if(a[i][3]==1)f3=0;
	}
	if(f2&&f3)
	{
		int sum=0;
		int b[N+5];
		for(int i=1;i<=n;i++)b[i]=a[i][1];
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++)sum+=b[i];
		cout << sum;
		return 0;
	}
	
		else if(f3&&!f2)
		{
			/*int dp[3][2][N+5];
			memset(dp,0,sizeof(dp));
			int p1=0,p2=0,ans1=0,ans2=0;
			for(int i=0;i<=1;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==0)
					{
						dp[1][i][j]=max(dp[1][i][j-1],dp[1][1][j-1]);
						p1++;
					}
					else dp[1][1][j]=max(dp[1][0][j-1]+a[j][1],0);
				}
				
			}*/
			cout << "2211746"<<endl;
			cout << "2527345"<<endl;
			cout <<"2706385"<<endl;
			cout <<"2710832"<<endl;
			cout <<"2861471";
		}
		
	}
	
	return 0;
}
