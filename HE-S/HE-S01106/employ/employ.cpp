#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,ans;
int c[N],p[N];
string s;
bool flag[N];
void check()
{
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=c[p[i]] || s[i]=='0')
			cnt++;
		else
			sum++;
	}
	ans=(ans+(sum>=m))%MOD;
}
void dfs(int t)
{
	if(t>n)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			p[t]=i;
			flag[i]=true;
			dfs(t+1);
			flag[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
