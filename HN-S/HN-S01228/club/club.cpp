#include<bits/stdc++.h>
#define def(i,a,b) for(int i=a;i<=b;i++)
#define udef(i,a,b) for(int i=a;i>=b;i--)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define m(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
using namespace std;
typedef int i32;
typedef long long i63;
const int N = 1e2 + 5, INF = 0x3f3f3f3f;
i32 _,n;
int a[N][4],b[N];
int dp[33][33][33][33],dg[201][101][101];
void work1()
{
	int ma = 0;
	m(dp,0);
	def(i,1,n)
	{
		def(j,1,3)
		{
			def(k,0,n/2)
			{
				def(l,0,n/2)
				{
					if(i - k - l > n / 2) continue;
					if(j == 1 && k != 0) dp[i][k][l][i - k - l] = max((int)dp[i-1][k - 1][l][i - k - l] + a[i][j], (int)dp[i][k][l][i-k-l]) ;
					if(j == 2 && l != 0) dp[i][k][l][i - k - l] = max((int)dp[i-1][k ][l- 1][i - k - l] + a[i][j], (int)dp[i][k][l][i-k-l]) ;
					if(j == 3 && i - k - l != 0) dp[i][k][l][i - k - l] = max((int)dp[i-1][k ][l][i - k - l - 1] + a[i][j], (int)dp[i][k][l][i-k-l]) ;
					ma = max(dp[i][k][l][i - k - l], ma);
				}
			}
		}
	}
	cout << ma << '\n';
}
void work2()
{
	i32 ans = 0;
	sort(b+1,b+1+n);
	i32 k = n/2;
	udef(i,n,1)
	{
		ans += b[i];
		k--;
		if(!k) break;
	 } 
	 cout << ans << '\n';
 } 
 void work3()
 {
 	int ma = 0;
	m(dp,0);
	def(i,1,n)
	{
		def(j,1,2)
		{
			def(k,0,n/2)
			{
					if(i - k  > n / 2) continue;
					if(j == 1 && k != 0) dg[i][k][i - k ] = max(dg[i-1][k - 1][i - k ] + a[i][j], dg[i][k][i-k]) ;
					if(j == 2 && i - k != 0) dg[i][k][i - k] = max((int)dg[i-1][k ][i - k - 1] + a[i][j], dg[i][k][i-k]) ;
					ma = max(dg[i][k][i - k], ma);
			}
		}
	}
	cout << ma << '\n';
 }
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> _;
	bool f = 0;
	while(_--)
	{
//		cout <<  _;
		cin >> n;
		def(i,1,n)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i] = a[i][1];
			if(a[i][2] != 0) f =1;
		}
		if(n <= 30 ) work1();
		else if(f) work3();
		else work2();
	}
	return 0;
}

