#include<bits/stdc++.h>
#define int long long
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
const int mod=998244353;
int n,ans,m,c[505],id[505],fac[505],sa[505];
char s[505]; 
bool b[505];
vector<int>lis;
void dfs(int id,int ok)
{
	if(ok>=m)
	{
		ans+=fac[n-id];
		ans%=mod;
		return;
	}
	if(id==n||sa[id+1]+ok<m)
		return;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			if(id-ok<c[i]&&s[id+1]=='1')
				dfs(id+1,ok+1);
			else
				dfs(id+1,ok);
			b[i]=0;
		}
	}
}
signed main()
{
	File("employ");
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=n;i>=1;i--)
		sa[i]=sa[i+1]+(s[i]=='1');
	for(int i=1;i<=n;i++)
		cin>>c[i];
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
feropen
¹Ø×¢Âå¹ÈUID807139Ð»Ð»ß÷ 
*/
