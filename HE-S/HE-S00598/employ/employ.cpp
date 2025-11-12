#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
using namespace std;
const int Imax=0x7fffffff;
const long long LLmax=0x7fffffffffffffff;
const int N=505;
const int Mod=998244353;
int n,m;
char ch;
int s[N];
int c[N];
vector<int> v;
int ans;
int vis[N];
void dfs(int x)
{
	if(x==n)
	{
		int cnt=0,lst=0,num=0;
		for(int i:v)
		{
			num++;
			if(lst>=c[i]) lst++;
			else if(!s[num]) lst++;
			else cnt++;
		}
		ans=(ans+(cnt>=m))%Mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1,v.push_back(i);
		dfs(x+1);
		vis[i]=0,v.pop_back();
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>ch,s[i]=ch-'0';
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(0);
	printf("%d",ans);
	return 0;
}
