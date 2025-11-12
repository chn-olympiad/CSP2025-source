#include<iostream>
#include<cstdio>
using namespace std;
long long ans,c[1000],n,m,i;
bool b[1100],pd;
string s;
const long long mo=998244353;
void dfs(long long d,long long sum)
{
	long long i;
	if(n-sum<m) return;
	if(d==n) 
	{
		ans=(ans+1)%mo;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]) continue;
		if(c[i]<=sum||s[d]!='1') 
		{
			sum++;
		}
		b[i]=1;
		dfs(d+1,sum);
		if(c[i]<=sum||s[d]!='1') sum--;
		b[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(i=1;i<=n;i++) scanf("%lld",&c[i]);
	dfs(0,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
