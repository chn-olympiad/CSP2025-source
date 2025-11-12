#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int N=510,P=998244353;
int n,m;
char s[N];
int c[N],a[N];
bool st[N];
LL ans=0;

void dfs(int u)
{
	if(u==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[a[i]])
			{
				cnt++;
				continue;
			}
			if(s[i]=='0') cnt++;
		}
		if(n-cnt>=m) ans=(ans+1)%P;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]) continue;
		st[i]=1;
		a[u]=i;
		dfs(u+1);
		st[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	bool flag=1;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			flag=0;
			continue;
		}
	}
	if(flag)
		for(int i=n;i>=1;i--) ans=ans*i%P;
	else dfs(1);
	printf("%lld",ans);
	
	return 0;
}
