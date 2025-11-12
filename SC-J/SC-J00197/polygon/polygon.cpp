#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 5010,Mod = 998244353;
int n,Max;
int f[N][N<<1];
int date[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>date[i],Max = max(Max,date[i]);
	Max *= 2;
	sort(date+1,date+1+n);
	f[0][0] = 1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=Max+1;j++)
			(f[i+1][min(Max+1,j+date[i+1])] += f[i][j]) %= Mod,(f[i+1][j] += f[i][j]) %= Mod;
	int ans = 0;
//	for(int i=1;i<=n;i++,cout<<"\n")
//		for(int j=0;j<=Max+1;j++)
//			cout<<f[i][j]<<" ";
//	return 0;
	for(int i=1;i<=n;i++)
		for(int j=date[i]+1;j<=Max+1;j++)
			(ans += f[i-1][j]) %= Mod;
	cout<<ans;
	return 0;
}