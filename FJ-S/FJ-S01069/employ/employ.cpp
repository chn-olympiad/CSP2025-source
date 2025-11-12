#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+1e2,mod=998244353;
int n,m,ans,a[N],c[N],v[N];
string s;
void dfs(int x,int y)
{
	if(y>n-m) return;
	if(x>n)
	{
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]) continue;
		v[i]=1;
		if(y>=c[i]||!a[x]) dfs(x+1,y+1);
		else dfs(x+1,y);
		v[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans;
}
//3 2
//101
//1 1 2

//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
