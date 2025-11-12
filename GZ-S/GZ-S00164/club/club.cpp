//GZ-S00164 遵义市第四中学 张槟  
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pail pair<int ,int>
const int N=1000+5;

ll read()
{
	int f=1,x=0;char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0';
	
	return f*x;
}
int dp[N][N>>1][4];
int f[N];
int a[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	int T=read();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int maxn=n/2;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=maxn;j++)
			{
				for(int k=0;k<=3;k++)
					dp[i][j][k]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]==0) a[0][1]++;
			if(a[i][2]==0) a[0][2]++;
			if(a[i][3]==0) a[0][2]++;
 //			dp[i][1][1]=a[i][1],dp[i][1][2]=a[i][2],dp[i][1][3]=a[i][3];
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=min(i,maxn);j++)
			{
					dp[i][j][1]=max(max(max(dp[i-1][j-1][1],dp[i-1][j][2]),dp[i-1][j][3])+a[i][1],dp[i-1][j-1][1]);
					dp[i][j][2]=max(max(max(dp[i-1][j][1],dp[i-1][j-1][2]),dp[i-1][j][3])+a[i][2],dp[i-1][j-1][2]);
					dp[i][j][3]=max(max(max(dp[i-1][j][1],dp[i-1][j][2]),dp[i-1][j-1][3])+a[i][3],dp[i-1][j-1][3]);
	//	m        
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i&&j<=maxn;j++)
			{

				ans=max(max(dp[i][j][1],dp[i][j][2]),dp[i][j][3]);
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
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8 
4 0 0

2
6
0 1 0
0 1 0
0 1 0
0 1 0
0 1 0
0 1 0
*/

