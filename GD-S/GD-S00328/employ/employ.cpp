//code by 201012280925LSY
#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353,N=510;
long long n,c[N],m,f[N],answer;
long long lim[N];
char a[N];
bool vis[N];
void DFS(long long step,long long now)
{
	if(step==n+1)
	{
		if(n-now>=m)
		{
			answer++;
			answer%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(a[step]=='0'||now>=c[i])DFS(step+1,now+1);
			else DFS(step+1,now);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],f[i]=f[i-1]+(a[i]=='0');
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	if(!f[n])
	{
		answer=1;
		for(int i=1;i<=n;++i)
		{
			answer*=i;
			answer%=MOD;
		}
		cout<<answer;
		return 0;
	}
	DFS(1,0);
	cout<<answer;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

