#include<iostream>//road 最小生成树 prim
#include<algorithm>
#include<cstring>
#include<queue>
#define PII pair<int,int>
using namespace std;
const int N=5e7+10,M=1e4+50;
long long p[N];
int f[N];
bool f1[N];
int n,m,t,t1;
string s;
long long sum;
void dfs(int p1)
{
	if(p1==n+1)
	{
		long long ss=0,s1=0;
		for(int i=0;i<s.size();i++)
		{
			if(ss>=f[i+1])
				continue;
			if(s[i]=='0')
				ss++;
			else
				s1++;
		}
		if(s1>=m)
			sum++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f1[i])
		{
			f1[i]=1;
			f[p1]=p[i];
			dfs(p1+1);
			f1[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	dfs(1);
	printf("%lld",sum);
	return 0;
}
