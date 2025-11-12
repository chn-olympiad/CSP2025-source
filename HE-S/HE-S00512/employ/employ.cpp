#include <bits/stdc++.h>
using namespace std;
const int N = 550,mod = 998244353;
int a[N],b[N];
char str[N];
int p[N],al;
bool vis[N];
int n,m;
int ans;
void init(int n)
{
	a[0]=1;
	for (int i=1;i<=n;i++)
		a[i]=(long long)a[i-1]*i%mod;
}
void dfszza(int id)
{
	if (id==n+1)
	{
		/*for (int i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<"\n";*/
		int outnum=0,oknum=0;
		for (int i=1;i<=n;i++)
		{
			if (outnum>=b[p[i]]||str[i]=='0') outnum++;
			else oknum++;
		}
		if (oknum>=m) ans++;
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		vis[i]=1;
		p[id]=i;
		dfszza(id+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,str+1);
	int num=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if (b[i]==0) num++;
	}
	int fl=1,cnt=0;
	for (int i=1;i<=n;i++)
		if (str[i]=='0') fl=0,cnt++;
	if (m>(n-num)||m>(n-cnt))
	{
		printf("0");
		return 0;
	}
	if (n<=18)
	{
		dfszza(1);
		printf("%d",ans);
		return 0;
	}
	if (fl)
	{
		init(n);
		printf("%d",a[n]);
		return 0;
	}
	printf("0");
	return 0;
}
