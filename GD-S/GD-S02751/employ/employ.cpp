#include<cstdio>
#define ll long long
using namespace std;
int n,m;
ll ans;
const int N=510;
const ll Mod=998244353;
char s[N];
int c[N];
bool used[N];
void dfs(int x,int t)
{
	if(x>n)
	{
		if(n-t>=m) ans++;
		if(ans>=Mod) ans-=Mod;
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(!used[i])
			{
				used[i]=true;
				if(t>=c[i]) dfs(x+1,t+1);
				else
				{
					if(s[x]=='0') dfs(x+1,t+1);
					else dfs(x+1,t);
				}
				used[i]=false;
			}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int sum=0,cnt=0;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		sum+=s[i]-'0';
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(!c[i]) cnt++;
	}
	if(n-cnt<m)
	{
		printf("0");
		return 0; 
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
