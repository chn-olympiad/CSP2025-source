#include<bits/stdc++.h>
#define ll long long
#define N (int)510
#define MOD 998244353
using namespace std;

ll n,m,ans;
ll d[N],c[N],s[N],p[N],zero[N],maxx,vis[N];
void dfs(int x,int y,int g)
{
	if(x>n)
	{
		if(y>=m)
			ans++,ans%=MOD;
		return;
	}
	//printf("B%lld %lld %lld %lld\n",x,y,s[maxx],s[zero[x]]);
	/*if(s[maxx]-s[zero[x]]<m-y)
		return;*/
	for(int i=1; i<=n; i++)
		if(!vis[i])
		{
			vis[i]=1;
			if(d[i]==0||c[i]<=g)
				dfs(x+1,y,g+1);
			else
				dfs(x+1,y+1,g);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld\n",&n,&m);
	for(int i=1; i<=n; i++)
	{
		char x=getchar();
		d[i]=x-'0';
		zero[i]=zero[i-1]+!d[i];
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&c[i]);
		p[c[i]]++;
		maxx=max(maxx,c[i]);
	}
	s[0]=p[0];
	for(int i=1; i<=maxx; i++)
		s[i]=s[i-1]+p[i];
	/*for(int i=1; i<=maxx; i++)
		printf("%lld ",p[i]);*/
	dfs(1,0,0);
	printf("%lld",ans%MOD);
	return 0;
}

