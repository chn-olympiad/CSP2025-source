#include<bits/stdc++.h>
#define int long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=5020,mo=998244353;
int n;
int a[N];
int f[N][N*2],g[N][N*2];
int res;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	fo(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	res=a[n]*2+1;
	f[0][0]=g[0][0]=1;
	fo(i,0,n-1)
		fo(j,0,res)
		{
			f[i+1][min(j+a[i+1],res)]+=g[i][j];
			f[i+1][min(j+a[i+1],res)]%=mo;
			g[i+1][min(j+a[i+1],res)]+=g[i][j];
			g[i+1][min(j+a[i+1],res)]%=mo;			
			g[i+1][j]+=g[i][j];
			g[i+1][j]%=mo;
		}
	int ans=0;
	fo(i,1,n)
		fo(j,2*a[i]+1,res)
			ans+=f[i][j],ans%=mo;
	cout<<ans;
	return 0;
}
