#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507,mod=998244353;
int n,m,a[N],bzA=0,ans; //cnt存储必然放弃的人 
bool bz[N];
string s;
void dfs(int d,int tot)
{
	if(tot+n-d+1<m) return;
	if(tot>=m)
	{
		int temp=1;
		for(int i=2;i<=n-d+1;i++) temp=(temp*i)%mod;
		ans=(ans+temp)%mod;
		return;
	}
	if(d>n) return;
	for(int i=1;i<=n;i++)
	{
		if(bz[i]==1) continue;
		bz[i]=1;
		if(s[d]=='1'&&d-1-tot<a[i]) dfs(d+1,tot+1);
		else dfs(d+1,tot);
		bz[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	int i,j,k;
	s=" "+s;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1') bzA++;
		scanf("%lld",&a[i]);
	} 
	dfs(1,0);
	cout << ans << endl;
	return 0;
}
