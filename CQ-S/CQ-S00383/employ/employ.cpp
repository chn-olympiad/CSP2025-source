#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
const int mod=998244353,N=505;
lo n,m,p[N],a[N],res;
string s;
bitset<N>vis;
void calc()
{
	lo cnt=0,sum=0;
	for(lo i=1;i<=n;i++)
	{
		if(cnt>=a[p[i]]||s[i-1]=='0'){cnt++;continue;}
		sum++;
	}
	(res+=(sum>=m))%=mod;
}
void dfs(lo k)
{
	if(k>n)return calc();
	for(lo i=1;i<=n;i++)
	{
		if(vis[i])continue;
		p[k]=i,vis[i]=1;
		dfs(k+1);
		vis[i]=0;
	}	
}
int main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(lo i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<res;
}
